// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Interfaces/PawnCombatInterface.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "GenericTeamAgentInterface.h"
#include "Character/Input/WarriorGameplayTags.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameplayEffectTypes.h"

#include "WarriorDebugHelper.h"

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

FGameplayTag UWarriorFunctionLibrary::ComputeHitReactDirectionTag(AActor* InAttack, AActor* InVictim, float& OutAngleDiff)
{
    check(InAttack && InVictim);

    const FVector VictimForward = InVictim->GetActorForwardVector();
    const FVector VictimToAttackerNormalized = (InAttack->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();

    const float DotResult = FVector::DotProduct(VictimForward, VictimToAttackerNormalized);
    OutAngleDiff = UKismetMathLibrary::DegAcos(DotResult);

    const FVector CrossResult = FVector::CrossProduct(VictimForward, VictimToAttackerNormalized);

    if (CrossResult.Z < 0.f) {
        OutAngleDiff *= -1.f;
    }


    if (OutAngleDiff >= -45.f && OutAngleDiff <= 45.f) {
        return WarriorGameplayTags::Shared_Status_HitReact_Front;
    }
    else if (OutAngleDiff < -45.f && OutAngleDiff >= -135.f) {
        return WarriorGameplayTags::Shared_Status_HitReact_Left;
    }
    else if (OutAngleDiff < -135.f || OutAngleDiff > 135.f) {
        return WarriorGameplayTags::Shared_Status_HitReact_Back;
    }
    else if (OutAngleDiff > 45.f && OutAngleDiff <= 135.f) {
        return WarriorGameplayTags::Shared_Status_HitReact_Right;
    }

    return WarriorGameplayTags::Shared_Status_HitReact_Front;
}

bool UWarriorFunctionLibrary::IsValidBlock(AActor* InAttacker, AActor* InDefender)
{
    check(InAttacker && InDefender);

    const float DotResult = FVector::DotProduct(InAttacker->GetActorForwardVector(), InDefender->GetActorForwardVector());

    return DotResult < -0.1f;
}

bool UWarriorFunctionLibrary::ApplyGameplayEffectSpecHandleToTargetActor(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{
    UWarriorAbilitySystemComponent* SourceASC = NativeGetWarriorASCFromActor(InInstigator);
    UWarriorAbilitySystemComponent* TargetASC = NativeGetWarriorASCFromActor(InTargetActor);

    FActiveGameplayEffectHandle ActiveGameplayEffectHandle = SourceASC->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data.Get(), TargetASC);

    return ActiveGameplayEffectHandle.WasSuccessfullyApplied();
}
