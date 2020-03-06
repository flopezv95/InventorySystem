// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IST_StoreObjectInteraction.generated.h"

UINTERFACE(MinimalAPI)
class UIST_StoreObjectInteraction : public UInterface
{
	GENERATED_BODY()
};

class INVENTORYSYSTEM_V1_API IIST_StoreObjectInteraction
{
	GENERATED_BODY()

protected:
	//
	UFUNCTION()
		virtual void StoreOrTakeOutItem() = 0;
};

