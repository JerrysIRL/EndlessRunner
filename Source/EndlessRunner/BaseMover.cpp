// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMover.h"

#include "EndlessRunnerGameModeBase.h"

// Sets default values
ABaseMover::ABaseMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(DefaultRoot);

}

// Called when the game starts or when spawned
void ABaseMover::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AEndlessRunnerGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void ABaseMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveObstacle(DeltaTime);

}

void ABaseMover::MoveObstacle(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	float PlatformSpeed = GameMode->GetMoveSpeed();
	
	FVector NewLocation = FVector(
		CurrentLocation.X += GetActorForwardVector().X * PlatformSpeed * DeltaTime,
		CurrentLocation.Y,
		CurrentLocation.Z
	);

	SetActorLocation(NewLocation);
}
