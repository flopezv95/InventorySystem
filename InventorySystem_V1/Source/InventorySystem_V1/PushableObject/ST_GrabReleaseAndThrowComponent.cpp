// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_GrabReleaseAndThrowComponent.h"
#include "../Item/ST_ThrowableItem.h"
#include "Math/Vector.h"
#include <Components/StaticMeshComponent.h>
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UST_GrabReleaseAndThrowComponent::UST_GrabReleaseAndThrowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UST_GrabReleaseAndThrowComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UST_GrabReleaseAndThrowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AST_ThrowableItem * UST_GrabReleaseAndThrowComponent::GrabObject(AST_ThrowableItem * objectToGrab)
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
		objectToGrab->Grab();
		return itemGrab;
	}
	else
	{
		return nullptr;
	}
}

void UST_GrabReleaseAndThrowComponent::Release()
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

void UST_GrabReleaseAndThrowComponent::Throw(FVector startLocation, FVector gravityValue)
{
	int numForTheLoop = (pathLifeTime / pathInterval);
	if (itemGrab != nullptr)
	{
		velocity = itemGrab->projectileMovementComponent->Velocity;
		for (int i = 0; i < numForTheLoop; i++)
		{
			if (!bIsHit)
			{
				int test = numForTheLoop;
				FPathPoints pointsToThePath = GetSegmentAtTime(startLocation, gravityValue, i*pathInterval, (i + 1)*pathInterval);
				FHitResult elementsToHit;
				FCollisionQueryParams traceParams;
				if (bUseDebugLine)
				{
					DrawDebugLine(GetWorld(), pointsToThePath.point1, pointsToThePath.point2, FColor::Blue, false, 0.5f);
				}
				else
				{
					CreateEffectBeam(pointsToThePath.point1, pointsToThePath.point2);
				}
				bIsHit = GetWorld()->LineTraceSingleByChannel(elementsToHit, pointsToThePath.point1, pointsToThePath.point2, ECollisionChannel::ECC_Visibility, traceParams);
			}
		}
		bIsHit = false;
	}
}

FPathPoints UST_GrabReleaseAndThrowComponent::GetSegmentAtTime(FVector startLocation, FVector gravityValue, float time1, float time2)
{
	ACharacter * Owner = Cast<ACharacter>(GetOwner());
		FPathPoints pointsToReturn;
		if (Owner)
		{
			FRotator playerRotation = Owner->GetControlRotation();
			FVector rotation = playerRotation.RotateVector(startLocation);
			FTransform transforForTheVelocity = UKismetMathLibrary::MakeTransform(rotation, playerRotation, FVector(1.0f, 1.0f, 1.0f));
			FVector finalVelocity = UKismetMathLibrary::TransformDirection(transforForTheVelocity, velocity);
			pointsToReturn.point1 = (startLocation) + (finalVelocity *time1) + (gravityValue*time1*time1*0.5f);
			pointsToReturn.point2 =(startLocation) + (finalVelocity *time2) + (gravityValue*time2*time2*0.5f);
		}
		return pointsToReturn;
}

void UST_GrabReleaseAndThrowComponent::CreateEffectBeam(FVector point1, FVector point2)
{
	BlueprintCreateBeam(point1, point2);
}

