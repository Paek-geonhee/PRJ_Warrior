// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"


class AWarriorWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8 {
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category ="Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);
	// 특정 태그로 스폰된 무기를 컨테이너에 등록. 이때, 등록 즉시 장착할 지 여부를 정해야 함.

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurruentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void ToggleWeaponColision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnWeaponHitTarget(AActor* HitActor);
	virtual void OnWeaponPulledFromTarget(AActor* InteractiveActor);
protected:
	TArray<AActor*> OverlappedActors;

private:
	// 아이템을 집어넣는 컨테이너
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
