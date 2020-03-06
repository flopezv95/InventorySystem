// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORYSYSTEM_V1_IST_ItemInteractuable_generated_h
#error "IST_ItemInteractuable.generated.h already included, missing '#pragma once' in IST_ItemInteractuable.h"
#endif
#define INVENTORYSYSTEM_V1_IST_ItemInteractuable_generated_h

#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact(); \
		P_NATIVE_END; \
	}


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact(); \
		P_NATIVE_END; \
	}


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIST_ItemInteractuable) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INVENTORYSYSTEM_V1_API, UIST_ItemInteractuable); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIST_ItemInteractuable); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(UIST_ItemInteractuable&&); \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(const UIST_ItemInteractuable&); \
public:


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(UIST_ItemInteractuable&&); \
	INVENTORYSYSTEM_V1_API UIST_ItemInteractuable(const UIST_ItemInteractuable&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INVENTORYSYSTEM_V1_API, UIST_ItemInteractuable); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIST_ItemInteractuable); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIST_ItemInteractuable)


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUIST_ItemInteractuable(); \
	friend struct Z_Construct_UClass_UIST_ItemInteractuable_Statics; \
public: \
	DECLARE_CLASS(UIST_ItemInteractuable, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/InventorySystem_V1"), INVENTORYSYSTEM_V1_API) \
	DECLARE_SERIALIZER(UIST_ItemInteractuable)


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_GENERATED_UINTERFACE_BODY() \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_GENERATED_UINTERFACE_BODY() \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IIST_ItemInteractuable() {} \
public: \
	typedef UIST_ItemInteractuable UClassType; \
	typedef IIST_ItemInteractuable ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_INCLASS_IINTERFACE \
protected: \
	virtual ~IIST_ItemInteractuable() {} \
public: \
	typedef UIST_ItemInteractuable UClassType; \
	typedef IIST_ItemInteractuable ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_9_PROLOG
#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_RPC_WRAPPERS \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORYSYSTEM_V1_API UClass* StaticClass<class UIST_ItemInteractuable>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID InventorySystem_V1_Source_InventorySystem_V1_Item_IST_ItemInteractuable_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
