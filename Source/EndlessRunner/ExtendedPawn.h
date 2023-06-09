// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ExtendedPawn.generated.h"

class AEndlessRunnerGameModeBase;

UCLASS()
class ENDLESSRUNNER_API AExtendedPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExtendedPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AEndlessRunnerGameModeBase* GameModeRef;

private:
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 50;

private:
	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess = "true"))
	void Move(float Value);

	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess = "true"))
	void CharCrouch();

	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess = "true"))
	void ResetRot();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
