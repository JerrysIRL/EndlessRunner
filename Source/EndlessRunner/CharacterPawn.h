// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "CharacterPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class ENDLESSRUNNER_API ACharacterPawn : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 50;


	void Move(float Value);

	void Crouch();

	void ResetRot();


public:
	// Sets default values for this pawn's properties
	ACharacterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
