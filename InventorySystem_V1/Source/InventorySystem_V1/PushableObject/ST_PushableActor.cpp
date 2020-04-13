// Fill out your copyright notice in the Description page of Project Settings.


#include "ST_PushableActor.h"
#include "GameFramework/Character.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
AST_PushableActor::AST_PushableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	objectToPush = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Push Object"));
	RootComponent = objectToPush;
	triggerXMovement = CreateDefaultSubobject<UBoxComponent>(TEXT("Movement X"));
	triggerXMovement->SetupAttachment(RootComponent);
	triggerYMovement = CreateDefaultSubobject<UBoxComponent>(TEXT("Movement Y"));
	triggerYMovement->SetupAttachment(RootComponent);
	physicConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Physics Constraint"));
	physicConstraint->SetupAttachment(RootComponent);
	//
	physicConstraint->ComponentName1.ComponentName = "Push Object";
	physicConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	physicConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	physicConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0.0f);
	physicConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Locked, 0.0f);
	physicConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
	physicConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Free, 0.0f);
	//
	objectToPush->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void AST_PushableActor::BeginPlay()
{
	Super::BeginPlay();
	objectToPush->SetMassOverrideInKg(NAME_None, massInkg);
}

// Called every frame
void AST_PushableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AST_PushableActor::Push()
{
	if (isThePlayerReadyToPush)
	{
		isBeenPushing = true;
		objectToPush->SetSimulatePhysics(true);
	}
}

void AST_PushableActor::Release()
{
	if (isThePlayerReadyToPush)
	{
		isBeenPushing = false;
		objectToPush->SetSimulatePhysics(false);
	}
}

void AST_PushableActor::PlayerIsCloseAxisX(AActor * actor, bool IsEnterOverlap)
{
	if (moveInXAxis)
	{
		PlayerIsClose(actor, IsEnterOverlap);
	}
}

void AST_PushableActor::PlayerIsCloseAxisY(AActor * actor, bool IsEnterOverlap)
{
	if (moveInYAxis)
	{
		PlayerIsClose(actor, IsEnterOverlap);
	}
}

void AST_PushableActor::PlayerIsClose(AActor * actor, bool IsEnterOverlap)
{
	ACharacter * firtsPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (actor)
		{
			if (actor == firtsPlayer)
			{
				isThePlayerReadyToPush = IsEnterOverlap;
				if (!IsEnterOverlap)
				{
					Release();
				}
			}
		}
}

