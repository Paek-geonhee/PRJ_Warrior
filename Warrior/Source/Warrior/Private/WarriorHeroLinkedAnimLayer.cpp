// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/Hero/WarriorHeroLinkedAnimLayer.h"
#include "Anim/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
    return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
