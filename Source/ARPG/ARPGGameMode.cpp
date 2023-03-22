// Copyright Epic Games, Inc. All Rights Reserved.

#include "ARPGGameMode.h"
#include "ARPGCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ARPGPlayerState.h"
#include "ARPGPlayerController.h"

AARPGGameMode::AARPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AARPGPlayerController::StaticClass();
	//static ConstructorHelpers::FClassFinder<AARPGPlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ARPGPlayerController"));
	//if (PlayerControllerBPClass.Class != NULL)
	//{


	//	PlayerControllerClass = PlayerControllerBPClass.Class;
	//}
	PlayerStateClass = AARPGPlayerState::StaticClass();
}
