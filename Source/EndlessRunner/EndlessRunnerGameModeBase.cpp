// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

#include "MovingPlatform.h"

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatform(FVector());
	for (int i = 1; i < StartingAmount; i++)
	{
		SpawnPlatform(GetSpawningPosition());
	}
	
}

void AEndlessRunnerGameModeBase::MovePlatform(AActor* Platform, FVector Position)
{
	Platform -> SetActorLocation(Position);
	AMovingPlatform* temp = Cast<AMovingPlatform>(Platform);
	SetNextPlatform(temp);
	
}

FVector AEndlessRunnerGameModeBase::GetSpawningPosition() const
{
	return LastPlatform->GetSpawnPointLocation();
}

void AEndlessRunnerGameModeBase::SpawnPlatform(FVector SpawnPos)
{
	UWorld* World = GetWorld();
	AMovingPlatform* PlatformPtr = World->SpawnActor<AMovingPlatform>(MovingPlatformBP, SpawnPos, FRotator());
	SetNextPlatform(PlatformPtr);
}

void AEndlessRunnerGameModeBase::SetNextPlatform(AMovingPlatform* Platform)
{
	LastPlatform = Platform;
}





