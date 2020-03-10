// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Item/ST_Item.h"
#include "ST_InventorySystemComponent.generated.h"

USTRUCT(Blueprintable)
struct FItemInTheInventory
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere)
		int numOfTheItem;
	// 
	UPROPERTY(EditAnywhere)
		AST_Item* item;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_V1_API UST_InventorySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString name;
	UPROPERTY(VisibleAnywhere)
		TArray<FItemInTheInventory> itemsInTheInventory;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		int maxSlotsInTheInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int numSlotsForRow;
	UPROPERTY(VisibleAnywhere)
		int numSlotsFree;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D anchorsMinimum;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D anchorsMaximum;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D alignment;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D position;

public:
	// Sets default values for this component's properties
	UST_InventorySystemComponent();
	UFUNCTION(BlueprintCallable)
		int GetNumberOfTheItemByIndex(int index);
	UFUNCTION(BlueprintCallable)
		AST_Item* GetItemByIndex(int index);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
		void Interact(AActor* ActorToInteract = nullptr);

private:
	bool isInTheInventory = false;
	bool createNewItem = true;
		
};
