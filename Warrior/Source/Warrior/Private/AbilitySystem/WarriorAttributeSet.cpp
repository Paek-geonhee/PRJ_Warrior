// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Character/Input/WarriorGameplayTags.h"
#include "WarriorFunctionLibrary.h"
#include "Interfaces/PawnUIInterface.h"
#include "Character/Components/UI/PawnUIComponent.h"
#include "Character/Components/UI/HeroUIComponent.h"


#include "WarriorDebugHelper.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UWarriorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid()) {
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("CachedPawnUIInterface has not implemented for %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel())
	
	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent, TEXT("PawnUIComponent is not valid for %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	Debug::Print(*GetOwningActor()->GetActorNameOrLabel());
	// Health Management
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute()) {
		float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
		
	}
	
	// Rage Management
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute()) {
		float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);

		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent()) {
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage() / GetMaxRage());
		}
	}

	// Death Process
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute()) {
		const float OldHeatlh = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHeatlh - DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		if (NewCurrentHealth == 0.f) {
			UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Shared_Status_Dead);
		}
	}
}
