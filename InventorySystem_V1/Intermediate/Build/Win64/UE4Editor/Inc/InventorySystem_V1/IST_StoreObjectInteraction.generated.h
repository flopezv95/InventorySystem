// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORYSYSTEM_V1_IST_StoreObjectInteraction_generated_h
#error "IST_StoreObjectInteraction.generated.h already included, missing '#pragma once' in IST_StoreObjectInteraction.h"
#endif
#define INVENTORYSYSTEM_V1_IST_StoreObjectInteraction_generated_h

#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStoreOrTakeOutItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StoreOrTakeOutItem(); \
		P_NATIVE_END; \
	}


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStoreOrTakeOutItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StoreOrTakeOutItem(); \
		P_NATIVE_END; \
	}


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIST_StoreObjectInteraction) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INVENTORYSYSTEM_V1_API, UIST_StoreObjectInteraction); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIST_StoreObjectInteraction); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(UIST_StoreObjectInteraction&&); \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(const UIST_StoreObjectInteraction&); \
public:


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(UIST_StoreObjectInteraction&&); \
	INVENTORYSYSTEM_V1_API UIST_StoreObjectInteraction(const UIST_StoreObjectInteraction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(INVENTORYSYSTEM_V1_API, UIST_StoreObjectInteraction); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIST_StoreObjectInteraction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIST_StoreObjectInteraction)


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUIST_StoreObjectInteraction(); \
	friend struct Z_Construct_UClass_UIST_StoreObjectInteraction_Statics; \
public: \
	DECLARE_CLASS(UIST_StoreObjectInteraction, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/InventorySystem_V1"), INVENTORYSYSTEM_V1_API) \
	DECLARE_SERIALIZER(UIST_StoreObjectInteraction)


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_GENERATED_UINTERFACE_BODY() \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_GENERATED_UINTERFACE_BODY() \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IIST_StoreObjectInteraction() {} \
public: \
	typedef UIST_StoreObjectInteraction UClassType; \
	typedef IIST_StoreObjectInteraction ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_INCLASS_IINTERFACE \
protected: \
	virtual ~IIST_StoreObjectInteraction() {} \
public: \
	typedef UIST_StoreObjectInteraction UClassType; \
	typedef IIST_StoreObjectInteraction ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_9_PROLOG
#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_RPC_WRAPPERS \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORYSYSTEM_V1_API UClass* StaticClass<class UIST_StoreObjectInteraction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID InventorySystem_V1_Source_InventorySystem_V1_StorageObject_IST_StoreObjectInteraction_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
