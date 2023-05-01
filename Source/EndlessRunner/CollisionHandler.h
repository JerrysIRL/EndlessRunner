// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "CollisionHandler.generated.h"


class AEndlessRunnerGameModeBase;
class AExtendedPawn;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENDLESSRUNNER_API UCollisionHandler : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int MaxHealthAmount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	int CurrentHealth;

	UFUNCTION()
	void ActorBeginOverlap( AActor* OverlappedActor, AActor* OtherActor);
	
	UPROPERTY()
	AExtendedPawn* Owner;
	
	void CheckForDeath() const;
	

public:	
	// Sets default values for this component's properties
	UCollisionHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
