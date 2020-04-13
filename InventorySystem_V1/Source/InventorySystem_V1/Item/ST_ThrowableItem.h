// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IST_ItemThrowable.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ST_ThrowableItem.generated.h"

UCLASS()
class INVENTORYSYSTEM_V1_API AST_ThrowableItem : public AActor, public IIST_ItemThrowable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AST_ThrowableItem();
	//
	UFUNCTION()
		virtual void Grab() override;
	//
	UFUNCTION()
		virtual void Release() override;
	//
	UFUNCTION()
		virtual void Throw() override;
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintGrab"))
		void BlueprintGrabEffect();
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintRelease"))
		void BlueprintReleaseEffect();
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintThrow"))
		void BlueprintThrowEffect();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Mesh
	UPROPERTY(EditAnywhere)
		UStaticMesh* meshObject;
	//Mesh
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* projectileMovementComponent;
	//
	UPROPERTY(EditAnywhere)
		class UMaterialInterface* objectMaterial1;
	//
	UPROPERTY(EditAnywhere)
		class UMaterialInterface* objectMaterial2;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UClass* itemClass;

};
