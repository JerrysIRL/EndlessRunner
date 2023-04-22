// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleSpawner.generated.h"

class AObstacle;
class AEndlessRunnerGameModeBase;
class AMovingPlatform;

UENUM()
enum SpawnAlternative
{
	Obstacle,
	Coin,
	MedPack
	
};
UCLASS()
class ENDLESSRUNNER_API AObstacleSpawner : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess ="true"))
	AMovingPlatform* PlatformRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AObstacle> ObstacleBP;

	TArray<FVector> PosArray;

	TArray<int> Pattern1 = {0, 0, 0, 1, 1, 2};

public:
	// Sets default values for this actor's properties
	AObstacleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
