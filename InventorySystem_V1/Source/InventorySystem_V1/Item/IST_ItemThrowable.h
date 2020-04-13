// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IST_ItemThrowable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIST_ItemThrowable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORYSYSTEM_V1_API IIST_ItemThrowable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//
	UFUNCTION()
		virtual void Grab() = 0;
	//
	UFUNCTION()
		virtual void Release() = 0;
	//
	UFUNCTION()
		virtual void Throw() = 0;
};
