// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ST_GrabReleaseAndThrowComponent.generated.h"

class AST_ThrowableItem;
class UParticleSystem;
class UParticleSystemComponent;

USTRUCT(Blueprintable)
struct FPathPoints
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector point1;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector point2;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_V1_API UST_GrabReleaseAndThrowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UST_GrabReleaseAndThrowComponent();
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
	//
	UPROPERTY(VisibleAnywhere)
		TArray<UParticleSystemComponent*> particlesForThePath;
	//
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* particlesSystemComp;
	//
	UPROPERTY(EditAnywhere)
		UParticleSystem * particleSystemToUse;
	//
	UPROPERTY(EditAnywhere)
		bool bUseDebugLine;

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
	//
	UFUNCTION(BlueprintCallable)
		FPathPoints GetSegmentAtTime(FVector startLocation, FVector gravityValue, float time1, float time2);
	//
	UFUNCTION(BlueprintCallable)
		void CreateEffectBeam(FVector point1, FVector point2);
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintCreateBeam"))
		void BlueprintCreateBeam(FVector point1, FVector point2);
private:
	bool bIsHit;
	FVector velocity;

		
};
