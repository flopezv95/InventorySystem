// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_Item.h"

// Sets default values
AST_Item::AST_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AST_Item* AST_Item::CopyFromAnotherItem(AST_Item * itemToCopy)
{
	AST_Item * itemToRet = NewObject<AST_Item>(AST_Item::StaticClass());
	itemToRet->itemProperties.specificType = itemToCopy->itemProperties.specificType;
	itemToRet->itemProperties.pickableType = itemToCopy->itemProperties.pickableType;
	itemToRet->itemProperties.imageToShowInTheInventory = itemToCopy->itemProperties.imageToShowInTheInventory;
	itemToRet->itemProperties.itemDescription.Description = itemToCopy->itemProperties.itemDescription.Description;
	itemToRet->itemProperties.itemDescription.Durability = itemToCopy->itemProperties.itemDescription.Durability;
	itemToRet->itemProperties.itemDescription.isStockable = itemToCopy->itemProperties.itemDescription.isStockable;
	itemToRet->itemProperties.itemDescription.itemName = itemToCopy->itemProperties.itemDescription.itemName;
	itemToRet->itemProperties.itemDescription.MaxStackSize = itemToCopy->itemProperties.itemDescription.MaxStackSize;
	return itemToRet;
}

// Called when the game starts or when spawned
void AST_Item::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AST_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AST_Item::Interact()
{
	if (itemProperties.pickableType == EPickableType::E_PICKABLE)
	{
		if (itemProperties.itemDescription.isStockable)
		{
			BlueprintStockableffect();
		}
		else
		{
			BlueprintTemporalffect();
		}
	}
	else
	{
		BlueprintConsumableffect();
	}
}

