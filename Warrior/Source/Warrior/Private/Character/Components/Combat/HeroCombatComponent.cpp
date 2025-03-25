// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/Combat/HeroCombatComponent.h"
#include "Items/Weapon/WarriorHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Character/Input/WarriorGameplayTags.h"
#include"WarriorDebugHelper.h"


AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
    return Cast<AWarriorHeroWeapon>(GetCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
    AWarriorHeroWeapon* Weapon = GetHeroCurrentEquippedWeapon();
    return Weapon->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
    if (OverlappedActors.Contains(HitActor)) return;

    OverlappedActors.AddUnique(HitActor);

    FGameplayEventData Data;
    Data.Instigator = GetOwningPawn();
    Data.Target = HitActor;

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        WarriorGameplayTags::Shared_Event_MeleeHit,
        Data
    );

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        WarriorGameplayTags::Player_Event_HitPause,
        FGameplayEventData()
    );
}

void UHeroCombatComponent::OnWeaponPulledFromTarget(AActor* InteractiveActor)
{
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        WarriorGameplayTags::Player_Event_HitPause,
        FGameplayEventData()
    );
}
