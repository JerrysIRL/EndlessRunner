// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh ->SetupAttachment(DefaultRoot);

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>("Spawn Point");
	SpawnPoint -> SetupAttachment(BaseMesh);

}

FVector AMovingPlatform::GetSpawnPointLocation() const
{
	return this->SpawnPoint->GetComponentLocation();
}


// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	UE_LOG(LogTemp,Warning, TEXT("CurrentPos is : %s"), *CurrentLocation.ToString())
	
	FVector NewLocation = FVector(
	CurrentLocation.X += GetActorForwardVector().X * PlatformSpeed *DeltaTime,
	CurrentLocation.Y,
	CurrentLocation.Z
	);
	
	SetActorLocation(NewLocation);
	
	

}

