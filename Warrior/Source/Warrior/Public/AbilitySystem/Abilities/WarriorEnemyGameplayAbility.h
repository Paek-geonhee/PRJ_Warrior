// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorEnemyGameplayAbility.generated.h"

class AWarriorEnemyCharacter;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class WARRIOR_API UWarriorEnemyGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	AWarriorEnemyCharacter* GetEnemyCharacterFromActorInfo();

	/*UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	AWarriorHeroController* GetEnemyControllerFromActorInfo();/*/

	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();


private:
	TWeakObjectPtr<AWarriorEnemyCharacter> CachedEnemyCharacter;

	//TWeakObjectPtr<UEnemyCombatComponent> CachedEnemyCombatComponent;

};
