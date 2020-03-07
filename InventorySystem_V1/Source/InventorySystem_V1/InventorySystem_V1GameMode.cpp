// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "InventorySystem_V1GameMode.h"
#include "InventorySystem_V1HUD.h"
#include "InventorySystem_V1Character.h"
#include "UObject/ConstructorHelpers.h"

AInventorySystem_V1GameMode::AInventorySystem_V1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AInventorySystem_V1HUD::StaticClass();
}
