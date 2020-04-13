// Fill out your copyright notice in the Description page of Project Settings.

#include "ST_InteractComponent.h"
#include "../Item/ST_Item.h"
#include "../Item/ST_ThrowableItem.h"
#include "../StorageObject/ST_StorageObject.h"
#include "../PushableObject/ST_PushableActor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../PushableObject/ST_GrabAndThrowComponent.h"

// Sets default values for this component's properties
UST_InteractComponent::UST_InteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UST_InteractComponent::Interact(AActor * ActorToInteract, bool IsInputRelease)
{
	if ((UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_ItemInteractuable::StaticClass()) || UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_StoreObjectInteraction::StaticClass())) && !IsInputRelease)
	{
		UST_InventorySystemComponent * inventorySystem = GetOwner()->FindComponentByClass<UST_InventorySystemComponent>();
		inventorySystem->Interact(ActorToInteract);
	}
	else if (UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_ObjectIsPushable::StaticClass()))
	{
		AST_PushableActor* pushableObject = Cast<AST_PushableActor>(ActorToInteract);
		if (pushableObject)
		{
			if (pushableObject->isBeenPushing)
			{
				pushableObject->Release();
			}
			else
			{
				pushableObject->Push();
			}
		}
	}
	else if (UKismetSystemLibrary::DoesImplementInterface(ActorToInteract, UIST_ItemThrowable::StaticClass()) && !IsInputRelease)
	{
		UST_GrabAndThrowComponent * grabAndThrownComponent = GetOwner()->FindComponentByClass<UST_GrabAndThrowComponent>();
		if (grabAndThrownComponent)
		{
			AST_ThrowableItem * grabObject = Cast<AST_ThrowableItem>(ActorToInteract);
			if (grabObject)
			{
				grabAndThrownComponent->GrabObject(grabObject);
			}
		}
	
	}
}


// Called when the game starts
void UST_InteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UST_InteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

