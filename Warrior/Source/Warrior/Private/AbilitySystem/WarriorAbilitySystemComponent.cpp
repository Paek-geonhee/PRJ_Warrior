// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(FGameplayTag InputTag)
{
	if (!InputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(FGameplayTag InputTag)
{

}
