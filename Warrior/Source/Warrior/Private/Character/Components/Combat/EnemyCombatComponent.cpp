// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/Combat/EnemyCombatComponent.h"
#include "Character/Input/WarriorGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorFunctionLibrary.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) {
		return;
	}

	OverlappedActors.AddUnique(HitActor);

    bool bIsValidBlock = false;

    const bool bIsPlayerBlocking = UWarriorFunctionLibrary::NativeDoesActorHaveTag(HitActor, WarriorGameplayTags::Player_Status_Blocking);
    const bool bIsMyAttackUnblockable = false;

    if (bIsPlayerBlocking && !bIsMyAttackUnblockable) {
        bIsValidBlock = UWarriorFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);
    }

    FGameplayEventData Data;
    Data.Instigator = GetOwningPawn();
    Data.Target = HitActor;

    if (bIsValidBlock) {
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            HitActor,
            WarriorGameplayTags::Player_Event_SuccessfulBlock,
            Data
        );
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
