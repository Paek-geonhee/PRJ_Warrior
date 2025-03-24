// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GEExactCalc/GEExactCalc_DamageTaken.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "Character/Input/WarriorGameplayTags.h"



struct FWarriorDamageCapture {

	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FWarriorDamageCapture() {
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DamageTaken, Target, false)
	}
};

static const FWarriorDamageCapture& GetWarriorDamageCapture() {
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}

UGEExactCalc_DamageTaken::UGEExactCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DamageTakenDef);
}

void UGEExactCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetWarriorDamageCapture().AttackPowerDef,
		EvaluateParameters,
		SourceAttackPower
	);
	//Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;
	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes) {
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Shared_SetByCaller_BaseDamage)) {
			BaseDamage = TagMagnitude.Value;
			//Debug::Print(TEXT("BaseDamage"), BaseDamage);
		}
		
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light)) {
			UsedLightAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("UsedLightAttackComboCount"), UsedLightAttackComboCount);
		}
		
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy)) {
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("UsedHeavyAttackComboCount"), UsedHeavyAttackComboCount);
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetWarriorDamageCapture().DefensePowerDef,
		EvaluateParameters,
		TargetDefensePower
	);
	//Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);

	if (UsedLightAttackComboCount != 0) {
		const float LightAttackDamagePortion = (UsedLightAttackComboCount - 1) * 0.05f + 1.f;

		BaseDamage *= LightAttackDamagePortion;
	}

	if (UsedHeavyAttackComboCount != 0) {
		const float HeavyAttackDamagePortion = UsedHeavyAttackComboCount * 0.15f + 1.f;

		BaseDamage *= HeavyAttackDamagePortion;
	}

	float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	//Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone);
	if (FinalDamageDone > 0) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetWarriorDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamageDone
			)
		);
	}
}
