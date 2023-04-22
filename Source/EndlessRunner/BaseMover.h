// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMover.generated.h"

class AEndlessRunnerGameModeBase;

UCLASS()
class ENDLESSRUNNER_API ABaseMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;
	
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY()
	AEndlessRunnerGameModeBase* GameMode;

	void MoveObstacle(float DeltaTime);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
