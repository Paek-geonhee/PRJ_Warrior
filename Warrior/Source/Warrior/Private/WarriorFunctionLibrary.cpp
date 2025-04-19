// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Interfaces/PawnCombatInterface.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "GenericTeamAgentInterface.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
    check(InActor);
    return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
    check(InActor);
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
    if (!ASC->HasMatchingGameplayTag(TagToAdd)) {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UWarriorFunctionLibrary::RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
    check(InActor);
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
    if (ASC->HasMatchingGameplayTag(TagToRemove)) {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
    UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
    return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType)
{
    OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}

UPawnCombatComponent* UWarriorFunctionLibrary::NativeGetPawnCombatComponentFromActorInfo(AActor* InActor)
{
    check(InActor);

    if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor)) {
        return PawnCombatInterface->GetPawnCombatComponent();
    }
    return nullptr;
}

UPawnCombatComponent* UWarriorFunctionLibrary::BP_GetPawnCombatComponentFromActorInfo(AActor* InActor, EWarriorValidType& OutValidType)
{
    UPawnCombatComponent* PawnCombatComponent = NativeGetPawnCombatComponentFromActorInfo(InActor);

    OutValidType = PawnCombatComponent ? EWarriorValidType::Valid : EWarriorValidType::Invalid;

    return PawnCombatComponent;
}

bool UWarriorFunctionLibrary::IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn)
{
    check(QueryPawn && TargetPawn);

    IGenericTeamAgentInterface* QueryTeamAgent = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
    IGenericTeamAgentInterface* TargetTeamAgent = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());

    if (QueryTeamAgent && TargetTeamAgent) {
       return (QueryTeamAgent->GetGenericTeamId() != TargetTeamAgent->GetGenericTeamId());
    }


    return false;
}

float UWarriorFunctionLibrary::GetScalableFloatValueAtLevel(const FScalableFloat& ScalableFloat, float InLevel)
{
    return ScalableFloat.GetValueAtLevel(InLevel);
}
