// Copyright Epic Games, Inc. All Rights Reserved.

#include "LestaTaskGameMode.h"
#include "LestaTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALestaTaskGameMode::ALestaTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
