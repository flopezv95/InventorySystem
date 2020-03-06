// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../InventorySystem/ST_InventorySystemComponent.h"
#include "IST_StoreObjectInteraction.h"
#include "ST_StorageObject.generated.h"

UCLASS()
class INVENTORYSYSTEM_V1_API AST_StorageObject : public AActor , public IIST_StoreObjectInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AST_StorageObject();
	UFUNCTION(BlueprintCallable)
		virtual void StoreOrTakeOutItem() override;
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintInteraction"))
		void BlueprintInteractioneffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
