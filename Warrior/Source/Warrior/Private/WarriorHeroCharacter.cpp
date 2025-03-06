// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DataAsset_InputConfig.h"
#include "WarriorInputComponent.h"
#include "WarriorGameplayTags.h"

#include "WarriorDebugHelper.h"

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

    Debug::Print(TEXT("Working"));
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

// void AWarriorHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
// {
//     // 입력에 따른 X, Y 값의 여부 및 정도를 확인하고 회전 방향에 대한 전방 벡터를 기준으로 캐릭터를 움직이게 함.
// 	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
//     const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

//     if(MovementVector.Y != 0.f)
//     {
//         const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
//         AddMovementInput(ForwardDirection, MovementVector.Y);
//     }

//     if(MovementVector.X != 0.f)
//     {
//         const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
//         AddMovementInput(RightDirection, MovementVector.X);
//     }
// }
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