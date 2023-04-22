// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMover.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"


UCLASS()
class ENDLESSRUNNER_API AObstacle : public ABaseMover
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstacle();

private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
