// Fill out your copyright notice in the Description page of Project Settings.

#include "ST_StorageObject.h"


// Sets default values
AST_StorageObject::AST_StorageObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AST_StorageObject::StoreOrTakeOutItem()
{
	BlueprintInteractioneffect();
}

// Called when the game starts or when spawned
void AST_StorageObject::BeginPlay()
{
	Super::BeginPlay();
	myInventorySystem = FindComponentByClass<UST_InventorySystemComponent>();

	for (int i = 0; i < itemsInTheStore.Num(); i++)
	{
		AST_Item * newItem = NewObject<AST_Item>(AST_Item::StaticClass());
		newItem->itemProperties = itemsInTheStore[i].itemProperties;
		FItemInTheInventory myNewItem;
		myNewItem.item = AST_Item::CopyFromAnotherItem(newItem);
		myNewItem.numOfTheItem = itemsInTheStore[i].numOfTheItem;
		itemsForCopy.Add(myNewItem);
	}
	if (myInventorySystem)
	{
		for (int i = 0; i < itemsForCopy.Num(); i++)
		{
			myInventorySystem->itemsInTheInventory.Add(itemsForCopy[i]);
		}
	}
}

// Called every frame
void AST_StorageObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

