// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Warrior/Public/WarriorGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWarriorGameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Warrior();
WARRIOR_API UClass* Z_Construct_UClass_AWarriorGameModeBase();
WARRIOR_API UClass* Z_Construct_UClass_AWarriorGameModeBase_NoRegister();
// End Cross Module References

// Begin Class AWarriorGameModeBase
void AWarriorGameModeBase::StaticRegisterNativesAWarriorGameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWarriorGameModeBase);
UClass* Z_Construct_UClass_AWarriorGameModeBase_NoRegister()
{
	return AWarriorGameModeBase::StaticClass();
}
struct Z_Construct_UClass_AWarriorGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "WarriorGameModeBase.h" },
		{ "ModuleRelativePath", "Public/WarriorGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWarriorGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWarriorGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Warrior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWarriorGameModeBase_Statics::ClassParams = {
	&AWarriorGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AWarriorGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWarriorGameModeBase()
{
	if (!Z_Registration_Info_UClass_AWarriorGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWarriorGameModeBase.OuterSingleton, Z_Construct_UClass_AWarriorGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWarriorGameModeBase.OuterSingleton;
}
template<> WARRIOR_API UClass* StaticClass<AWarriorGameModeBase>()
{
	return AWarriorGameModeBase::StaticClass();
}
AWarriorGameModeBase::AWarriorGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWarriorGameModeBase);
AWarriorGameModeBase::~AWarriorGameModeBase() {}
// End Class AWarriorGameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWarriorGameModeBase, AWarriorGameModeBase::StaticClass, TEXT("AWarriorGameModeBase"), &Z_Registration_Info_UClass_AWarriorGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWarriorGameModeBase), 3675622286U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorGameModeBase_h_361178358(TEXT("/Script/Warrior"),
	Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
