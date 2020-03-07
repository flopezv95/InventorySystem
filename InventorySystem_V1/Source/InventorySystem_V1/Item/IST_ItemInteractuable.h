// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IST_ItemInteractuable.generated.h"

UINTERFACE(MinimalAPI)
class UIST_ItemInteractuable : public UInterface
{
	GENERATED_BODY()
};

class INVENTORYSYSTEM_V1_API IIST_ItemInteractuable
{
	GENERATED_BODY()

protected:
	//
	UFUNCTION()
		virtual void Interact() = 0;
};

