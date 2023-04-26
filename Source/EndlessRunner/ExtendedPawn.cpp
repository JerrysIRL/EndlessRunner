// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtendedPawn.h"

#include "EndlessRunnerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AExtendedPawn::AExtendedPawn()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AExtendedPawn::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AExtendedPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AExtendedPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AExtendedPawn::CharCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AExtendedPawn::ResetRot);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AExtendedPawn::Move);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AExtendedPawn::DoJump);
}

void AExtendedPawn::DoJump()
{
	Jump();
}

void AExtendedPawn::Move(float Value)
{
	FVector MovementVector = FVector(0, Value * MovementSpeed * GetWorld()->GetDeltaSeconds(), 0);
	AddActorLocalOffset(MovementVector, true);
}

void AExtendedPawn::CharCrouch()
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Pitch = 270;
	SetActorRotation(CurrentRotation);
}

void AExtendedPawn::ResetRot()
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Pitch = 0;
	SetActorRotation(CurrentRotation);
}
