// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawner.h"
#include "EndlessRunnerGameModeBase.h"
#include "MovingPlatform.h"
#include "Obstacle.h"

// Sets default values
AObstacleSpawner::AObstacleSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
	if (PlatformRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("I am: %s"), *PlatformRef->GetActorNameOrLabel())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I am: null"))
	}


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
	PosArray.Add(CurrentPos + ZOffset + YOffset*2); // Top Right
	for (auto Element : PosArray)
	{
		GetWorld()->SpawnActor<AObstacle>(ObstacleBP, Element, FRotator());
	}
	UE_LOG(LogTemp, Warning, TEXT("Obstacle %d"),Obstacle );
	UE_LOG(LogTemp, Warning, TEXT("Obstacle %d"),Coin );
	UE_LOG(LogTemp, Warning, TEXT("Obstacle %d"),MedPack );
}

// Called every frame
void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
