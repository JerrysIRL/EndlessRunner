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
	UPROPERTY(EditDefaultsOnly, Category="ActorSpawning")
	TSubclassOf<AMovingPlatform> MovingPlatformBP;

	UPROPERTY()
	AMovingPlatform* LastPlatform;
	FVector NextSpawningPosition;

	UPROPERTY(EditAnywhere)
	int StartingAmount = 10;

private:
	UFUNCTION(BlueprintCallable)
	void SpawnPlatform(FVector SpawnPos);

public:
	UFUNCTION(BlueprintCallable)
	void MovePlatform(AActor* Platform, FVector Position);

	UFUNCTION()
	FVector GetSpawningPosition() const;
	
	UFUNCTION()
	void SetNextPlatform(AMovingPlatform* Platform);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
