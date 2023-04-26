// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"
#include "ObstacleSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "MovingPlatform.h"



void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnInitialPlatforms();
	
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AObstacleSpawner::StaticClass());
	ObstacleSpawner = Cast<AObstacleSpawner>(FoundActor);
	
	GetWorldTimerManager().SetTimer(SpeedTimerHandle,this, &AEndlessRunnerGameModeBase::AddSpeed, SpeedIncreaseRate, true);
}

void AEndlessRunnerGameModeBase::MovePlatform(AActor* Platform, FVector Position)
{
	Platform->SetActorLocation(Position);
	AMovingPlatform* temp = Cast<AMovingPlatform>(Platform);
	SetNextPlatform(temp);
	MovedPlatformCount++;
	SpawnObstacleWave();
}

FVector AEndlessRunnerGameModeBase::GetSpawningPosition() const
{
	return LastPlatform->GetSpawnPointLocation();
}

void AEndlessRunnerGameModeBase::GameOverEvent_Implementation()
{
	
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


void AEndlessRunnerGameModeBase::SpawnInitialPlatforms()
{
	SpawnPlatform(FVector());
	for (int i = 1; i < StartingAmount; i++)
	{
		SpawnPlatform(GetSpawningPosition());
	}
}

void AEndlessRunnerGameModeBase::SpawnObstacleWave()
{
	if (MovedPlatformCount == AmountOfPlatformsToPass)
	{
		ObstacleSpawner->SpawnObstacleWave();
		MovedPlatformCount = 0;
	}
}	

float AEndlessRunnerGameModeBase::GetMoveSpeed() const
{
	return MoveSpeed;
}

void AEndlessRunnerGameModeBase::AddSpeed()
{
	MoveSpeed -= SpeedIncrease;
	if(MoveSpeed <= SpeedLimit)
	{
		GetWorldTimerManager().ClearTimer(SpeedTimerHandle);
	}
}

void AEndlessRunnerGameModeBase::SetFinalScore(float Score)
{
	FinalScore = Score;
}

TArray<int> AEndlessRunnerGameModeBase::SortHighScores(TArray<int> ArrayToSort)
{
	TArray<int> temp = ArrayToSort;
	Algo::Sort(temp);
	return temp;
}
