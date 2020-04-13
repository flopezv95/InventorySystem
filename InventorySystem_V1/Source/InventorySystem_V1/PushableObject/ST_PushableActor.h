// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IST_ObjectIsPushable.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"
#include "ST_PushableActor.generated.h"

UCLASS()
class INVENTORYSYSTEM_V1_API AST_PushableActor : public AActor, public IIST_ObjectIsPushable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AST_PushableActor();
	//
	UPROPERTY(EditDefaultsOnly, Category = "Static Mesh")
		UStaticMeshComponent* objectToPush;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Movement Trigger")
		UBoxComponent* triggerXMovement;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Movement Trigger")
		UBoxComponent* triggerYMovement;
	//
	UPROPERTY(EditDefaultsOnly, Category = "Physics")
		UPhysicsConstraintComponent* physicConstraint;
	//
	UPROPERTY(VisibleAnywhere , BlueprintReadWrite)
		bool isThePlayerReadyToPush;
	//
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isBeenPushing;
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool moveInXAxis;
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool moveInYAxis;
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float massInkg = 800.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//
	virtual void Push() override;
	//
	virtual void Release() override;
	//
	UFUNCTION(BlueprintCallable)
		void PlayerIsCloseAxisX(AActor* actor, bool IsEnterOverlap);
	UFUNCTION(BlueprintCallable)
		void PlayerIsCloseAxisY(AActor* actor, bool IsEnterOverlap);
private:
	UFUNCTION()
		void PlayerIsClose(AActor* actor, bool IsEnterOverlap);

};
