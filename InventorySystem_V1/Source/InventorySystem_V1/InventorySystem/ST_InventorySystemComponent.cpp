// Fill out your copyright notice in the Description page of Project Settings.

#include "ST_InventorySystemComponent.h"
#include "../StorageObject/ST_StorageObject.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UST_InventorySystemComponent::UST_InventorySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


int UST_InventorySystemComponent::GetNumberOfTheItemByIndex(int index)
{
	int ret = 0;
	if (itemsInTheInventory.Num()-1 >= index)
	{
		ret = itemsInTheInventory[index].numOfTheItem;
	}
	return ret;
}

AST_Item * UST_InventorySystemComponent::GetItemByIndex(int index)
{
	AST_Item * ret = nullptr;
	if (itemsInTheInventory.Num()-1 >= index)
	{
		ret = itemsInTheInventory[index].item;
	}
	return ret;
}

void UST_InventorySystemComponent::ShowTheInventory()
{
	ShowInventory();
}

// Called when the game starts
void UST_InventorySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	numSlotsFree = maxSlotsInTheInventory;
	originalPosition = position;
	// ...
	
}

void UST_InventorySystemComponent::Interact(AActor * ActorToInteract)
{
	TSubclassOf<UIST_ItemInteractuable> interfaceToPick;
	TSubclassOf<UIST_StoreObjectInteraction> storeInterface;
	if (UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_ItemInteractuable::StaticClass()))
	{
		AST_Item * item = Cast<AST_Item>(ActorToInteract);
		if (item)
		{
			if (item->itemProperties.itemDescription.isStockable)
			{
				isInTheInventory = false;
				for (int i= 0; i < itemsInTheInventory.Num(); i++)
				{
					if (itemsInTheInventory[i].item->itemProperties.specificType == item->itemProperties.specificType)
					{
						
						if (itemsInTheInventory[i].numOfTheItem < itemsInTheInventory[i].item->itemProperties.itemDescription.MaxStackSize)
						{
							isInTheInventory = true;
							itemsInTheInventory[i].numOfTheItem ++;
						}
						else
						{
							isInTheInventory = false;
							//Display message=Can't stock more of this specific item
						}
					}
				}
				if ((numSlotsFree != 0 && !isInTheInventory))
				{
					FItemInTheInventory myNewItem;
					myNewItem.item = AST_Item::CopyFromAnotherItem(item);
					myNewItem.numOfTheItem = 1;
					itemsInTheInventory.Add(myNewItem);
					numSlotsFree--;
				}
				else
				{
					//Display message=Can't stock more items in the inventory
				}
			}
			item->Interact();
		}
	}
	else if (UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_StoreObjectInteraction::StaticClass()))
	{
		AST_StorageObject * storeObject = Cast<AST_StorageObject>(ActorToInteract);
		if (storeObject)
		{
			position = positionWhenAStoreIsOpen;
			isThePlayerOpenAnOnbjectStore = true;
			ShowInventory();
			storeObject->StoreOrTakeOutItem();
		}
	}
}


// Called every frame
void UST_InventorySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

