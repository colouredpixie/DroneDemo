// Copyright Epic Games, Inc. All Rights Reserved.

#include "DroneDemoGameMode.h"
#include "DroneDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADroneDemoGameMode::ADroneDemoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
