// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IST_ItemInteractuable.h"
#include "ST_Item.generated.h"

UENUM(BlueprintType)
enum class EPickableType :uint8
{
	
	E_PICKABLE UMETA(DisplayName = "PICKABLE"),
	E_NOTPICKABLE UMETA(DisplayName = "NOTPICKABLE"),
};

UENUM(BlueprintType)
enum class ESpecificType :uint8
{
	E_GUN UMETA(DisplayName = "GUN"),
	E_ROCK UMETA(DisplayName = "ROCK"),
	E_MEAT UMETA(DisplayName = "MEAT"),
	E_CONDOMS UMETA(DisplayName = "CONDOMS"),
};

USTRUCT(Blueprintable)
struct FItemDescription
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString itemName;
	// 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isStockable;
	// 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isConsumable;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int MaxStackSize;
	//  
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Description;
	//  
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Durability;

};

USTRUCT(Blueprintable)
struct FItemProperties
{
	GENERATED_BODY()
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EPickableType pickableType;
	// 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ESpecificType specificType;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UObject* imageToShowInTheInventory;
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UClass* itemClass;
	//  
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FItemDescription itemDescription;
};



UCLASS()
class INVENTORYSYSTEM_V1_API AST_Item : public AActor , public IIST_ItemInteractuable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AST_Item();
	UFUNCTION(BlueprintCallable)
		virtual void Interact() override;
	UFUNCTION(BlueprintCallable)
		void ConsumableEffect();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintStockable"))
		void BlueprintStockableffect();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintConsumable"))
		void BlueprintConsumableffect();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BlueprintTemporal"))
		void BlueprintTemporalffect();
	UFUNCTION()
		static AST_Item* CopyFromAnotherItem(AST_Item* itemToCopy);

public:	
	//
	virtual void Tick(float DeltaTime) override;
	//Interact is the activation of this object. The lever will be pressed, and your activatable object will be activated (E.G.: bridges, gates, etc)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FItemProperties itemProperties;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
