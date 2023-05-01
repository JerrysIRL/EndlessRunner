// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"
#include "ObstacleSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "MovingPlatform.h"

AEndlessRunnerGameModeBase::AEndlessRunnerGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnInitialPlatforms();
	
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AObstacleSpawner::StaticClass());
	ObstacleSpawner = Cast<AObstacleSpawner>(FoundActor);
	
	GetWorldTimerManager().SetTimer(SpeedTimerHandle,this, &AEndlessRunnerGameModeBase::AddSpeed, SpeedIncreaseRate, true);
}

void AEndlessRunnerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Score += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("Dodged : %s"), DodgedLastWave ? TEXT("True") : TEXT("false") );
	
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

void AEndlessRunnerGameModeBase::SetDodgedWaveBool(bool value)
{
	DodgedLastWave = value;
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
		if(DodgedLastWave == true)
		{
			// 20% chance to get all coins wave
			int Random = FMath::RandRange(0, 9);
			UE_LOG(LogTemp, Warning, TEXT("Random value is: %d"), Random);
			if(Random == 1)
			{
				ObstacleSpawner->SpawnCoinWave();
				MovedPlatformCount = 0;
				return;
			}
		}
		ObstacleSpawner->SpawnObstacleWave();
		MovedPlatformCount = 0;
	}
}	

float AEndlessRunnerGameModeBase::GetMoveSpeed() const
{
	return MoveSpeed;
}

void AEndlessRunnerGameModeBase::AddToCurrentScore(float Points)
{
	Score += Points;
}


void AEndlessRunnerGameModeBase::AddSpeed()
{
	MoveSpeed -= SpeedIncrease;
	if(MoveSpeed <= SpeedLimit)
	{
		GetWorldTimerManager().ClearTimer(SpeedTimerHandle);
	}
}

void AEndlessRunnerGameModeBase::SetFinalScore(float ScoreToAdd)
{
	FinalScore = ScoreToAdd;
}

TArray<int> AEndlessRunnerGameModeBase::SortHighScores(TArray<int> ArrayToSort)
{
	TArray<int> temp = ArrayToSort;
	Algo::Sort(temp);
	return temp;
}

float AEndlessRunnerGameModeBase::GetScore() const
{
	return Score;
}

void AEndlessRunnerGameModeBase::GameOverEvent_Implementation()
{
	
}
