// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilitySets.IsEmpty()) {
		for (const TSubclassOf<UWarriorEnemyGameplayAbility>& Ability : EnemyCombatAbilitySets) {
			if (!Ability) continue;

			FGameplayAbilitySpec AbilitySpec(Ability.Get());
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
