// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/WarriorBaseAnimInstance.h"
#include "WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstance::DoesOwnerHasTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner()) {
       return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
    }
    return false;
}
