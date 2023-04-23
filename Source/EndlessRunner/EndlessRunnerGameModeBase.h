// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MovingPlatform.h"
#include "EndlessRunnerGameModeBase.generated.h"


class AObstacleSpawner;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Actor Spawning")
	TSubclassOf<AMovingPlatform> MovingPlatformBP;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = -500;

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
	
	FVector NextSpawningPosition;

private:
	UFUNCTION(BlueprintCallable)
	void SpawnPlatform(FVector SpawnPos);

public:
	UFUNCTION(BlueprintCallable)
	void MovePlatform(AActor* Platform, FVector Position);

	UFUNCTION()
	FVector GetSpawningPosition() const;

	UFUNCTION(BlueprintCallable)
	void SetNextPlatform(AMovingPlatform* Platform);

	float GetMoveSpeed() const;


protected:
	void SpawnInitialPlatforms();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnObstacleWave();
};
