// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"



// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ACharacterPawn::Move );

}

void ACharacterPawn::Move(float Value)
{
	float yFloat = FMath::Clamp(Value * MovementSpeed * GetWorld()->GetDeltaSeconds(), MinValue, MaxValue);
	UE_LOG(LogTemp, Warning, TEXT("YValue : %f"), yFloat);
	FVector MovementVector = FVector(0, yFloat,0);
	AddActorLocalOffset(MovementVector, true);
	UE_LOG(LogTemp, Warning, TEXT("InputValue is : %f"), Value);
}