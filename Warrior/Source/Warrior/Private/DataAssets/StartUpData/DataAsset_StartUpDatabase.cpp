// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDatabase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "GameplayEffect.h"

void UDataAsset_StartUpDatabase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbility(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbility(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty()) {
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects) {
			if (!EffectClass) continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();

			InASCToGive->ApplyGameplayEffectToSelf(
				EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext()
			);
		}
	}
}

void UDataAsset_StartUpDatabase::GrantAbility(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive) {
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
