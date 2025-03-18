// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;
class UDataAsset_StartUpDatabase;

UCLASS()
class WARRIOR_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UWarriorAttributeSet* WarriorAttributeSet;

	// 엔티티가 가져야하는 게임플레이 능력의 종류
	// Given 어빌리티와 Trigger 어빌리티가 들어있고, 이들에 대한 초기화 및 부여 기능을 가진 에셋
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDatabase> CharacterStartUpData;

public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const {return WarriorAbilitySystemComponent;}

	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }
};
