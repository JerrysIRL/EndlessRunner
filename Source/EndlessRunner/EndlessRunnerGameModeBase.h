// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlatform.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly,Category="ActorSpawning")
	TSubclassOf<AMovingPlatform> MovingPlatformBP;

	FVector NextSpawningPosition;

	UPROPERTY(EditAnywhere)
	int StartingAmount =10;

private:
	UFUNCTION(BlueprintCallable)
	void MovePlatform(AActor* Platform, FVector Position);

	UFUNCTION(BlueprintCallable)
	void SpawnPlatform(FVector SpawnPos);

	UFUNCTION()
	void SetNextSpawningPosition(FVector NextSpawnPos);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
