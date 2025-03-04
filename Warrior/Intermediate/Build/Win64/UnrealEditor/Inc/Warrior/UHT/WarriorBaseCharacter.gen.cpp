// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Warrior/Public/WarriorBaseCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWarriorBaseCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Warrior();
WARRIOR_API UClass* Z_Construct_UClass_AWarriorBaseCharacter();
WARRIOR_API UClass* Z_Construct_UClass_AWarriorBaseCharacter_NoRegister();
// End Cross Module References

// Begin Class AWarriorBaseCharacter
void AWarriorBaseCharacter::StaticRegisterNativesAWarriorBaseCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWarriorBaseCharacter);
UClass* Z_Construct_UClass_AWarriorBaseCharacter_NoRegister()
{
	return AWarriorBaseCharacter::StaticClass();
}
struct Z_Construct_UClass_AWarriorBaseCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WarriorBaseCharacter.h" },
		{ "ModuleRelativePath", "Public/WarriorBaseCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWarriorBaseCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWarriorBaseCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Warrior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorBaseCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWarriorBaseCharacter_Statics::ClassParams = {
	&AWarriorBaseCharacter::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWarriorBaseCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AWarriorBaseCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWarriorBaseCharacter()
{
	if (!Z_Registration_Info_UClass_AWarriorBaseCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWarriorBaseCharacter.OuterSingleton, Z_Construct_UClass_AWarriorBaseCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWarriorBaseCharacter.OuterSingleton;
}
template<> WARRIOR_API UClass* StaticClass<AWarriorBaseCharacter>()
{
	return AWarriorBaseCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWarriorBaseCharacter);
AWarriorBaseCharacter::~AWarriorBaseCharacter() {}
// End Class AWarriorBaseCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorBaseCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWarriorBaseCharacter, AWarriorBaseCharacter::StaticClass, TEXT("AWarriorBaseCharacter"), &Z_Registration_Info_UClass_AWarriorBaseCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWarriorBaseCharacter), 2748110854U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorBaseCharacter_h_4260447689(TEXT("/Script/Warrior"),
	Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorBaseCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_PRJ_Warrior_Warrior_Source_Warrior_Public_WarriorBaseCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
