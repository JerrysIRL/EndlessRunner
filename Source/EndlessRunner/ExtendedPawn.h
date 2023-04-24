// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ExtendedPawn.generated.h"

UCLASS()
class ENDLESSRUNNER_API AExtendedPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExtendedPawn();

private:
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 50;


private:
	void Move(float Value);

	void CharCrouch();

	void ResetRot();
	
	void DoJump();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
