// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InventorySystem_V1/Item/IST_ItemInteractuable.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIST_ItemInteractuable() {}
// Cross Module References
	INVENTORYSYSTEM_V1_API UClass* Z_Construct_UClass_UIST_ItemInteractuable_NoRegister();
	INVENTORYSYSTEM_V1_API UClass* Z_Construct_UClass_UIST_ItemInteractuable();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_InventorySystem_V1();
	INVENTORYSYSTEM_V1_API UFunction* Z_Construct_UFunction_UIST_ItemInteractuable_Interact();
// End Cross Module References
	void UIST_ItemInteractuable::StaticRegisterNativesUIST_ItemInteractuable()
	{
		UClass* Class = UIST_ItemInteractuable::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &IIST_ItemInteractuable::execInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/IST_ItemInteractuable.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIST_ItemInteractuable, nullptr, "Interact", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIST_ItemInteractuable_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIST_ItemInteractuable_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UIST_ItemInteractuable_NoRegister()
	{
		return UIST_ItemInteractuable::StaticClass();
	}
	struct Z_Construct_UClass_UIST_ItemInteractuable_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIST_ItemInteractuable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem_V1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UIST_ItemInteractuable_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UIST_ItemInteractuable_Interact, "Interact" }, // 1182951417
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIST_ItemInteractuable_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Item/IST_ItemInteractuable.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIST_ItemInteractuable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIST_ItemInteractuable>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIST_ItemInteractuable_Statics::ClassParams = {
		&UIST_ItemInteractuable::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UIST_ItemInteractuable_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UIST_ItemInteractuable_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIST_ItemInteractuable()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIST_ItemInteractuable_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIST_ItemInteractuable, 2933715964);
	template<> INVENTORYSYSTEM_V1_API UClass* StaticClass<UIST_ItemInteractuable>()
	{
		return UIST_ItemInteractuable::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIST_ItemInteractuable(Z_Construct_UClass_UIST_ItemInteractuable, &UIST_ItemInteractuable::StaticClass, TEXT("/Script/InventorySystem_V1"), TEXT("UIST_ItemInteractuable"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIST_ItemInteractuable);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
