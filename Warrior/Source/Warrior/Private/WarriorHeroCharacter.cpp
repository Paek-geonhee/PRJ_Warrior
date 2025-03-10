// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/Input/DataAsset_InputConfig.h"
#include "Character/Input/WarriorInputComponent.h"
#include "Character/Input/WarriorGameplayTags.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDatabase.h"
#include "Character/Components/Combat/HeroCombatComponent.h"

#include "WarriorDebugHelper.h"



void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}
AWarriorHeroCharacter::AWarriorHeroCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);

    // 실제 적용 여부 에디터에서 확인 필요
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
    //

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f,55.f,65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,500.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));

}
void AWarriorHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    checkf(InputConfigDataAsset, TEXT("Forgot to assign valid dataasset"));
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

    check(Subsystem);

    Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

    UWarriorInputComponent* WarrriorInputComponent = CastChecked<UWarriorInputComponent>(PlayerInputComponent);


    // 인풋 함수를 바인딩하는 과정.
    WarrriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
    WarrriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}


void AWarriorHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{	
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0.f,Controller->GetControlRotation().Yaw,0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection,MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection,MovementVector.X);
	}
}
void AWarriorHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
    if(LookAxisVector.X != 0.f)
    {
        AddControllerYawInput(LookAxisVector.X);
    }

    if(LookAxisVector.Y != 0.f)
    {
        AddControllerPitchInput(LookAxisVector.Y);
    }
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 소프트 레퍼런스를 사용하는 해당 코드의 경우
	// IsValid를 사용하기 위해선, 데이터가 로드된 상태에서 유효한 데이터가 로드 되었는지를 확인하는 것.
	// 최초 상태에서는 로드가 아직 진행되지 않았기 때문에, 유효한 데이터를 검사하는 게 아닌 로드 여부를 검사
	if (!CharacterStartUpData.IsNull()) {
		// 스타트업 데이터가 있는 경우
		if (UDataAsset_StartUpDatabase* LoadedData = CharacterStartUpData.LoadSynchronous()) {
			LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
		}
	}
}