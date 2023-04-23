// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMover.h"
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

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseMover> CoinBP;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseMover> MedPackBP;

	UPROPERTY()
	AEndlessRunnerGameModeBase* GameMode;

	TArray<FVector> PosArray;

	TArray<int> PatternOne = {Obstacle, Obstacle, Obstacle, Coin, Coin, MedPack};

private:
	void InitializeSpawnPositions();

public:
	// Sets default values for this actor's properties
	AObstacleSpawner();
	
	UFUNCTION(BlueprintCallable)
	void SpawnObstacleWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
