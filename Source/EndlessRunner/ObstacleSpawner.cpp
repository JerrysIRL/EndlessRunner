// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawner.h"
#include "EndlessRunnerGameModeBase.h"
#include "MovingPlatform.h"
#include "Obstacle.h"
#include "Algo/RandomShuffle.h"



// Sets default values
AObstacleSpawner::AObstacleSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}


void AObstacleSpawner::InitializeSpawnPositions()
{
	FBox Box = PlatformRef->GetComponentsBoundingBox(false, false);
	auto PlatformSize = Box.GetSize();
	FVector YOffset = FVector(0, PlatformSize.Y / 3, 0);
	FVector ZOffset = FVector(0, 0, 150);
	FVector CurrentPos = GetActorLocation();

	PosArray.Add(CurrentPos); // Bottom Left
	PosArray.Add(CurrentPos + YOffset); // Bottom middle
	PosArray.Add(CurrentPos + YOffset * 2); // Bottom Right
	PosArray.Add(CurrentPos + ZOffset); // Top Left
	PosArray.Add(CurrentPos + ZOffset + YOffset); // Top Middle
	PosArray.Add(CurrentPos + ZOffset + YOffset * 2); // Top Right
}

// Called when the game starts or when spawned
void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<AEndlessRunnerGameModeBase>(GetWorld()->GetAuthGameMode());
	PatternsArray.Add(PatternOne);
	PatternsArray.Add(PatternTwo);
	PatternsArray.Add(PatternThree);
	
	InitializeSpawnPositions();
	SpawnObstacleWave();
	
}

// Called every frame
void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AObstacleSpawner::SpawnObstacleWave()
{
	auto WaveToSpawn = ReturnRandomWave();
	for (int i = 0; i < PosArray.Num(); i++)
	{
		switch (WaveToSpawn[i])
		{
			case Obstacle:
				GetWorld()->SpawnActor<AObstacle>(ObstacleBP, PosArray[i], FRotator(0)); break;
			case Coin:
				GetWorld()->SpawnActor<ABaseMover>(CoinBP, PosArray[i], FRotator(0)); break;
			case MedPack:
				GetWorld()->SpawnActor<ABaseMover>(MedPackBP, PosArray[i], FRotator(0)); break;
			default: break;
		}
	}
}

void AObstacleSpawner::SpawnCoinWave()
{
	for (int i = 0; i < PosArray.Num(); i++)
	{
		GetWorld()->SpawnActor<ABaseMover>(CoinBP, PosArray[i], FRotator(0));
	}
}

TArray<int> AObstacleSpawner::ReturnRandomWave()
{
	int index = FMath::RandRange(0, PatternsArray.Num()-1);
	auto ShuffledArray = PatternsArray[index];
	Algo::RandomShuffle(ShuffledArray);
	return ShuffledArray;
}
	
