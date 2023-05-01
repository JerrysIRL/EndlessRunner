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

	TArray<int> ReturnRandomWave();

	TArray<FVector> PosArray;
	
	// 4 Different waves.
	TArray<int> PatternOne = {Obstacle, Obstacle, Obstacle, Coin, Coin, MedPack};
	TArray<int> PatternTwo = {Obstacle, Obstacle,Obstacle,Obstacle, Coin, Coin};
	TArray<int> PatternThree ={Obstacle, Obstacle,Obstacle,Obstacle, Obstacle, MedPack};
	TArray<int> CoinsOnlyPattern = {Coin, Coin, Coin, Coin, Coin, Coin};
	
	// Array that hold all the Patterns
	TArray<TArray<int>> PatternsArray = {PatternOne, PatternTwo, PatternThree};
	

private:
	void InitializeSpawnPositions();

public:
	
	AObstacleSpawner();
	
	UFUNCTION()
	void SpawnCoinWave();
	
	UFUNCTION(BlueprintCallable)
	void SpawnObstacleWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
