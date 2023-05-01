// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "BoxTrigger.generated.h"

class AEndlessRunnerGameModeBase;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENDLESSRUNNER_API UBoxTrigger : public UBoxComponent
{
	GENERATED_BODY()
	UBoxTrigger();

private:
	UPROPERTY()
	AEndlessRunnerGameModeBase* GameModeRef;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
