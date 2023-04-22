// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMover.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class AEndlessRunnerGameModeBase;

UCLASS()
class ENDLESSRUNNER_API AMovingPlatform : public ABaseMover
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	UArrowComponent* SpawnPoint;


protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Sets default values for this actor's properties
	AMovingPlatform();
	FVector GetSpawnPointLocation() const;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
