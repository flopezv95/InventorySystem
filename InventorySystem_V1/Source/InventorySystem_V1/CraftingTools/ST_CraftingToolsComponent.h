// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Item/ST_Item.h"
#include "ST_CraftingToolsComponent.generated.h"

UENUM(BlueprintType)
enum class EToolType :uint8
{
	E_CONSTRUCTION UMETA(DisplayName = "CONSTRUCTION"),
	E_WEAPONS UMETA(DisplayName = "WEAPONS"),
	E_TANKPARTS UMETA(DisplayName = "TANK PARTS"),
	E_CLOTHE UMETA(DisplayName = "CLOTHE"),
	E_CAMP UMETA(DisplayName = "CAMP ELEMENT"),
};

USTRUCT(Blueprintable)
struct FRawMaterialsInTheInventory
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UClass* rawMaterial;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int numOfTheRawMaterialInTheInventory;
};

USTRUCT(Blueprintable)
struct FRawMaterials
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AST_Item>  rawMaterial;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int numOfTheRawMaterialNecessaryForTheTool;
	//  
	UPROPERTY(BlueprintReadOnly)
		bool IsAlreadyEnougthMaterial;
};

USTRUCT(Blueprintable)
struct FTools
{
	GENERATED_BODY()
	//  
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UClass* itemClass;
	//  
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Description;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UObject* toolImage;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UObject* toolDescriptionImage;
	//  
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsReadyToCraft;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FRawMaterials> itemsForCraftTheTool;
};

USTRUCT(Blueprintable)
struct FClassOfElementsToCraft
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D imageSize;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UObject* classToolImage;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int numSlotsForRow;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EToolType toolType;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FTools> toolsInThisType;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_V1_API UST_CraftingToolsComponent : public UActorComponent
{
	GENERATED_BODY()


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FClassOfElementsToCraft> toolsForCraft;
	UPROPERTY(BlueprintReadOnly)
		TArray<FRawMaterialsInTheInventory> rawMaterialInTheInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D anchorsMinimum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D anchorsMaximum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D alignment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D position;

public:	
	// Sets default values for this component's properties
	UST_CraftingToolsComponent();
	//
	UFUNCTION(BlueprintCallable)
		void UpdateToolsCraft();
	//
	UFUNCTION()
		void UpdateNumOfRawMaterials(UClass* rawMaterial);
	//
	UFUNCTION(BlueprintCallable)
		int GetNumOfRawMaterial(UClass* rawMaterial);
	//
	UFUNCTION(BlueprintCallable)
		void CraftTool(int toolTypeIndex, int toolIndex);
	//
	UFUNCTION(BlueprintCallable)
		void IsToolReadyToCraft();
	//
	UFUNCTION(BlueprintCallable)
		TArray<FTools> GetToolsByType(EToolType toolType);
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "ShowTheCraftingToolsWindow"))
		void ShowCraftTools();
	//
	UFUNCTION(BlueprintCallable)
		void ShowTheCraftToolsWindow();
	//
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "UpdateRawMaterials"))
		void UpdateTheRawMaterials(int toolIndex);
	//
	UFUNCTION(BlueprintCallable)
		void UpdateRawMaterial(int toolIndex);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
};
