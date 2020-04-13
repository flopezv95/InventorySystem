// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_GrabAndThrowComponent.h"
#include "../Item/ST_ThrowableItem.h"
#include "Math/Vector.h"
#include <Components/StaticMeshComponent.h>

// Sets default values for this component's properties
UST_GrabAndThrowComponent::UST_GrabAndThrowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UST_GrabAndThrowComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UST_GrabAndThrowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AST_ThrowableItem * UST_GrabAndThrowComponent::GrabObject(AST_ThrowableItem * objectToGrab)
{
	if (itemGrab == nullptr)
	{
		itemGrab = objectToGrab;
		if (objectToGrab->meshObject != nullptr)
		{
			UStaticMeshComponent* weaponMesh = nullptr;
			TArray<UStaticMeshComponent*> Components;
			GetOwner()->GetComponents<UStaticMeshComponent>(Components);
			for (int32 i = 0; i < Components.Num(); i++) //Count is zero
			{
				weaponMesh = Components[i]; //null
				if (weaponMesh->GetName().Equals(nameOfTheStaticMesh)) {
					break;
				}
			}
			if (weaponMesh)
			{
				objectMesh = weaponMesh;
				weaponMesh->SetStaticMesh(objectToGrab->meshObject);
				if (objectToGrab->objectMaterial1 != nullptr)
				{
					weaponMesh->SetMaterial(0, objectToGrab->objectMaterial1);
				}
				if (objectToGrab->objectMaterial2 != nullptr)
				{
					weaponMesh->SetMaterial(0, objectToGrab->objectMaterial2);
				}
			}
		}
		return itemGrab;
	}
	else
	{
		return nullptr;
	}
}

void UST_GrabAndThrowComponent::Release()
{
	if (itemGrab != nullptr)
	{
		if (objectMesh != nullptr)
		{
			FVector Start = (objectMesh->GetComponentLocation()) + (objectMesh->GetForwardVector() * distToSpawnAndReleaseTheObject);
			FRotator Rotator = objectMesh->GetComponentRotation();
			FActorSpawnParameters newObjectSpawnInfo;
			newObjectSpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<AActor>(itemGrab->itemClass, Start, Rotator, newObjectSpawnInfo);
			itemGrab = nullptr;
			objectMesh->SetStaticMesh(nullptr);
		}
	}
}

void UST_GrabAndThrowComponent::Throw(FVector startLocation, FVector gravityValue)
{
	int numForTheLoop = (pathInterval / pathInterval);
	for (int i = 0; i < numForTheLoop ; i++)
	{
		if (!bIsHit)
		{

		}
	}
}

FPointsToPath UST_GrabAndThrowComponent::GetSegmentAtTime(FVector startLocation, FVector gravityValue, float time1, float time2)
{
	FPointsToPath pointsToReturn;

	return pointsToReturn;
}

