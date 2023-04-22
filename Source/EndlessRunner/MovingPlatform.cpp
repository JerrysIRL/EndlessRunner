// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "EndlessRunnerGameModeBase.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("Spawn Point");
	SpawnPoint->SetupAttachment(BaseMesh);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	BoundingBox = GetComponentsBoundingBox(false, false);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveObstacle(DeltaTime);
}

FVector AMovingPlatform::GetSpawnPointLocation() const
{
	return SpawnPoint->GetComponentLocation();
}

FBox AMovingPlatform::GetPlatformBounds() const
{
	return BoundingBox;
	
}
