// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

#include "MovingPlatform.h"
#include "Components/ArrowComponent.h"

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatform(FVector());
	for (int i = 1; i < StartingAmount; i++)
	{
		SpawnPlatform(NextSpawningPosition);
	}
	
}

void AEndlessRunnerGameModeBase::MovePlatform(AActor* Platform, FVector Position)
{
	//Platform ->SetActorLocation(Position);
	
}

void AEndlessRunnerGameModeBase::SpawnPlatform(FVector SpawnPos)
{
	UWorld* World = GetWorld();
	AMovingPlatform* PlatformPtr = World->SpawnActor<AMovingPlatform>(MovingPlatformBP, SpawnPos, FRotator());
	SetNextSpawningPosition(PlatformPtr->GetSpawnPointLocation());
}

void AEndlessRunnerGameModeBase::SetNextSpawningPosition(FVector SpawnPos)
{
	NextSpawningPosition = SpawnPos;
}





