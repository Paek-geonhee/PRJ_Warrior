// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDatabase.h"
#include "Engine/AssetManager.h"

#include "WarriorDebugHelper.h"

AWarriorEnemyCharacter::AWarriorEnemyCharacter() {
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}

UPawnCombatComponent* AWarriorEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

void AWarriorEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartData();
}

void AWarriorEnemyCharacter::InitEnemyStartData()
{
	if (CharacterStartUpData.IsNull()) return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (CharacterStartUpData.IsValid()) {
					UDataAsset_StartUpDatabase* LoadData = CharacterStartUpData.Get();

					LoadData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);

					Debug::Print(TEXT("Enemy StartUpData Loaded"));
				}
			}
		)
	);
	
}
