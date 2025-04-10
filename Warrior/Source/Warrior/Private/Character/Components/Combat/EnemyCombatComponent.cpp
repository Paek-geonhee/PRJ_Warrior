// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/Combat/EnemyCombatComponent.h"
#include "Character/Input/WarriorGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) {
		return;
	}

	OverlappedActors.AddUnique(HitActor);

    bool bIsValidBlock = false;

    const bool bIsPlayerBlocking = false;
    const bool bIsMyAttackUnblockable = false;

    if (bIsPlayerBlocking && !bIsMyAttackUnblockable) {
        
    }

    FGameplayEventData Data;
    Data.Instigator = GetOwningPawn();
    Data.Target = HitActor;

    if (bIsValidBlock) {
        
    }
    else {
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            GetOwningPawn(),
            WarriorGameplayTags::Shared_Event_MeleeHit,
            Data
        );
    }

    

    //UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
    //    GetOwningPawn(),
    //    WarriorGameplayTags::Player_Event_HitPause,
    //    FGameplayEventData()
    //);
}

void UEnemyCombatComponent::OnWeaponPulledFromTarget(AActor* InteractiveActor)
{

}
