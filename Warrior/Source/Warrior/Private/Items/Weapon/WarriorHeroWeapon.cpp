// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon/WarriorHeroWeapon.h"

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitySpecHandles() const
{
    return GrantedAbilitySpecHandles;
}

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InAbilitySpecHandles)
{
    GrantedAbilitySpecHandles = InAbilitySpecHandles;
}
