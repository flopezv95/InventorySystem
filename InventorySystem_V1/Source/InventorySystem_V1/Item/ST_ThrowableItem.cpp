// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_ThrowableItem.h"

// Sets default values
AST_ThrowableItem::AST_ThrowableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Comp"));

}

void AST_ThrowableItem::Grab()
{
	BlueprintGrabEffect();
}

void AST_ThrowableItem::Release()
{
	BlueprintReleaseEffect();
}

void AST_ThrowableItem::Throw()
{
	BlueprintThrowEffect();
}

// Called when the game starts or when spawned
void AST_ThrowableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AST_ThrowableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

