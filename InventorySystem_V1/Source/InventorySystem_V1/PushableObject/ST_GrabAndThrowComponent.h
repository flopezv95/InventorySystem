// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ST_GrabAndThrowComponent.generated.h"

class AST_ThrowableItem;

USTRUCT()
struct FPointsToPath
{
	GENERATED_BODY()
	//
	UPROPERTY()
		FVector point1;
	UPROPERTY()
		FVector point2;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_V1_API UST_GrabAndThrowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UST_GrabAndThrowComponent();
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AST_ThrowableItem * itemGrab;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString nameOfTheStaticMesh;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float distToSpawnAndReleaseTheObject = 50.0f;
	//
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* objectMesh = nullptr;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Throw")
		float pathLifeTime;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Throw")
		float pathInterval;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//
	UFUNCTION()
		AST_ThrowableItem * GrabObject(AST_ThrowableItem * objectToGrab);
	//
	UFUNCTION(BlueprintCallable)
		void Release();
	//
	UFUNCTION(BlueprintCallable)
		void Throw(FVector startLocation, FVector gravityValue);

private:
	//
	bool bIsHit;
	FPointsToPath GetSegmentAtTime(FVector startLocation, FVector gravityValue,float time1,float time2);
		
};
