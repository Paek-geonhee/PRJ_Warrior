// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorHeroCharacter.h"
#include "WarriorDebugHelper.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

    Debug::Print(TEXT("Working"));
}
AWarriorHeroCharacter::AWarriorHeroCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    CameraBoom->SetupAttachment(GetRootComponent()); 
    CameraBoom->TargetArmLength = 200.f;
    CameraBoom->SocketOffset = FVector(0,55.f,65.f);
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
    FollowCamera->bUsePawnControlRotation = false;
 

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0,500.f,0);
    GetCharacterMovement()->MaxWalkSpeed = 400.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}