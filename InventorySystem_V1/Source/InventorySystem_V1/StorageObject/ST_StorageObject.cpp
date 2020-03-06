// Fill out your copyright notice in the Description page of Project Settings.

#include <Engine/World.h>
#include "Components/ArrowComponent.h"
#include "ST_StorageObject.h"

// Sets default values
AST_StorageObject::AST_StorageObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AST_StorageObject::StoreOrTakeOutItem()
{
	BlueprintInteractioneffect();
}

// Called when the game starts or when spawned
void AST_StorageObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AST_StorageObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

