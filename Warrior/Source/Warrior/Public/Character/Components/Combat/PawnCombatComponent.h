// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"


class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category ="WarriorCombat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);
	// 특정 태그로 스폰된 무기를 컨테이너에 등록. 이때, 등록 즉시 장착할 지 여부를 정해야 함.

	UFUNCTION(BlueprintCallable, Category = "WarriorCombat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "WarriorCombat")
	FGameplayTag CurruentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "WarriorCombat")
	AWarriorWeaponBase* GetCurrentEquippedWeapon() const;


private:
	// 아이템을 집어넣는 컨테이너
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
