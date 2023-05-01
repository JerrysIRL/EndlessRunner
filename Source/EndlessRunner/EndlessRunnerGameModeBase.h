// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/EngineTypes.h"
#include "EndlessRunnerGameModeBase.generated.h"



class AObstacleSpawner;
class AMovingPlatform;

UCLASS(Blueprintable, BlueprintType)
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Actor Spawning")
	TSubclassOf<AMovingPlatform> MovingPlatformBP;
	
	UPROPERTY(EditAnywhere, Category="GameSpeed")
	float MoveSpeed = -500;
	
	UPROPERTY(EditAnywhere, Category="GameSpeed")
	float SpeedLimit= -2000;
	
	UPROPERTY(EditAnywhere, Category="GameSpeed")
	float SpeedIncrease = 30;
	/** Timer delay in seconds for the Speed increase */
	UPROPERTY(EditAnywhere, Category="GameSpeed")
	float SpeedIncreaseRate= 2;

	UPROPERTY(EditAnywhere, Category="Obstacle Spawner")
	int AmountOfPlatformsToPass = 5;
	
	UPROPERTY()
	AMovingPlatform* LastPlatform;

	UPROPERTY()
	AObstacleSpawner* ObstacleSpawner;

	UPROPERTY(EditAnywhere)
	int StartingAmount = 10;
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	int MovedPlatformCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	float FinalScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	float Score = 0;

	bool DodgedLastWave = false;
	
	FVector NextSpawningPosition;

	FTimerHandle SpeedTimerHandle;

private:
	
	UFUNCTION(BlueprintCallable)
	void SpawnPlatform(FVector SpawnPos);

	UFUNCTION()
	void SpawnObstacleWave();
	
	UFUNCTION()
	void AddSpeed();

	UFUNCTION(BlueprintPure)
	TArray<int> SortHighScores(TArray<int> ArrayToSort);

public:
	AEndlessRunnerGameModeBase();
	
	UFUNCTION(BlueprintNativeEvent)
	void GameOverEvent();
	
	UFUNCTION(BlueprintCallable)
	void MovePlatform(AActor* Platform, FVector Position);

	UFUNCTION()
	FVector GetSpawningPosition() const;

	UFUNCTION(BlueprintCallable)
	void SetNextPlatform(AMovingPlatform* Platform);

	void SetDodgedWaveBool(bool value);

	void SetFinalScore(float Score);
	
	float GetMoveSpeed() const;

	void AddToCurrentScore(float Points);

	float GetScore() const;

protected:
	void SpawnInitialPlatforms();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void Tick(float DeltaTime) override;
};
