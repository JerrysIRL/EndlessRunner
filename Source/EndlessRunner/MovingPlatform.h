// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ENDLESSRUNNER_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	UArrowComponent* SpawnPoint;

	UPROPERTY(EditAnywhere)
	float PlatformSpeed = -300;

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	
	 FVector GetSpawnPointLocation() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
