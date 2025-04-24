// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Warrior/Public/AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAbilityTask_ExecuteTaskOnTick() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilityTask();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
UPackage* Z_Construct_UPackage__Script_Warrior();
WARRIOR_API UClass* Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick();
WARRIOR_API UClass* Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_NoRegister();
WARRIOR_API UFunction* Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature();
// End Cross Module References

// Begin Delegate FOnAbilityTaskTickDelegate
struct Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics
{
	struct _Script_Warrior_eventOnAbilityTaskTickDelegate_Parms
	{
		float DeltaTime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Warrior_eventOnAbilityTaskTickDelegate_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::NewProp_DeltaTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Warrior, nullptr, "OnAbilityTaskTickDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::_Script_Warrior_eventOnAbilityTaskTickDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::_Script_Warrior_eventOnAbilityTaskTickDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAbilityTaskTickDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnAbilityTaskTickDelegate, float DeltaTime)
{
	struct _Script_Warrior_eventOnAbilityTaskTickDelegate_Parms
	{
		float DeltaTime;
	};
	_Script_Warrior_eventOnAbilityTaskTickDelegate_Parms Parms;
	Parms.DeltaTime=DeltaTime;
	OnAbilityTaskTickDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnAbilityTaskTickDelegate

// Begin Class UAbilityTask_ExecuteTaskOnTick Function ExecuteTaskOnTick
struct Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics
{
	struct AbilityTask_ExecuteTaskOnTick_eventExecuteTaskOnTick_Parms
	{
		UGameplayAbility* OwningAbility;
		UAbilityTask_ExecuteTaskOnTick* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Warrior|AbilityTasks" },
		{ "DefaultToSelf", "OwningAbility" },
		{ "HidePin", "OwningAbility" },
		{ "ModuleRelativePath", "Public/AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningAbility;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::NewProp_OwningAbility = { "OwningAbility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_ExecuteTaskOnTick_eventExecuteTaskOnTick_Parms, OwningAbility), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_ExecuteTaskOnTick_eventExecuteTaskOnTick_Parms, ReturnValue), Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::NewProp_OwningAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick, nullptr, "ExecuteTaskOnTick", nullptr, nullptr, Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::AbilityTask_ExecuteTaskOnTick_eventExecuteTaskOnTick_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::AbilityTask_ExecuteTaskOnTick_eventExecuteTaskOnTick_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilityTask_ExecuteTaskOnTick::execExecuteTaskOnTick)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_OwningAbility);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAbilityTask_ExecuteTaskOnTick**)Z_Param__Result=UAbilityTask_ExecuteTaskOnTick::ExecuteTaskOnTick(Z_Param_OwningAbility);
	P_NATIVE_END;
}
// End Class UAbilityTask_ExecuteTaskOnTick Function ExecuteTaskOnTick

// Begin Class UAbilityTask_ExecuteTaskOnTick
void UAbilityTask_ExecuteTaskOnTick::StaticRegisterNativesUAbilityTask_ExecuteTaskOnTick()
{
	UClass* Class = UAbilityTask_ExecuteTaskOnTick::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteTaskOnTick", &UAbilityTask_ExecuteTaskOnTick::execExecuteTaskOnTick },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAbilityTask_ExecuteTaskOnTick);
UClass* Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_NoRegister()
{
	return UAbilityTask_ExecuteTaskOnTick::StaticClass();
}
struct Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h" },
		{ "ModuleRelativePath", "Public/AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAbilityTickTask_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//~ End UGameplayTask interface\n" },
#endif
		{ "ModuleRelativePath", "Public/AbilitySystem/AbilityTasks/AbilityTask_ExecuteTaskOnTick.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAbilityTickTask;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAbilityTask_ExecuteTaskOnTick_ExecuteTaskOnTick, "ExecuteTaskOnTick" }, // 4177537934
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAbilityTask_ExecuteTaskOnTick>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::NewProp_OnAbilityTickTask = { "OnAbilityTickTask", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAbilityTask_ExecuteTaskOnTick, OnAbilityTickTask), Z_Construct_UDelegateFunction_Warrior_OnAbilityTaskTickDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAbilityTickTask_MetaData), NewProp_OnAbilityTickTask_MetaData) }; // 155999173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::NewProp_OnAbilityTickTask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilityTask,
	(UObject* (*)())Z_Construct_UPackage__Script_Warrior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::ClassParams = {
	&UAbilityTask_ExecuteTaskOnTick::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::Class_MetaDataParams), Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick()
{
	if (!Z_Registration_Info_UClass_UAbilityTask_ExecuteTaskOnTick.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAbilityTask_ExecuteTaskOnTick.OuterSingleton, Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAbilityTask_ExecuteTaskOnTick.OuterSingleton;
}
template<> WARRIOR_API UClass* StaticClass<UAbilityTask_ExecuteTaskOnTick>()
{
	return UAbilityTask_ExecuteTaskOnTick::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAbilityTask_ExecuteTaskOnTick);
UAbilityTask_ExecuteTaskOnTick::~UAbilityTask_ExecuteTaskOnTick() {}
// End Class UAbilityTask_ExecuteTaskOnTick

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_AbilitySystem_AbilityTasks_AbilityTask_ExecuteTaskOnTick_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAbilityTask_ExecuteTaskOnTick, UAbilityTask_ExecuteTaskOnTick::StaticClass, TEXT("UAbilityTask_ExecuteTaskOnTick"), &Z_Registration_Info_UClass_UAbilityTask_ExecuteTaskOnTick, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAbilityTask_ExecuteTaskOnTick), 2604025034U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_AbilitySystem_AbilityTasks_AbilityTask_ExecuteTaskOnTick_h_1127998740(TEXT("/Script/Warrior"),
	Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_AbilitySystem_AbilityTasks_AbilityTask_ExecuteTaskOnTick_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_AbilitySystem_AbilityTasks_AbilityTask_ExecuteTaskOnTick_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
