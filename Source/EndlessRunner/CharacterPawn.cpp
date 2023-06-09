// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComp");
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	BaseMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArm);
	

}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();
	//Jump();
	
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	/*Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ACharacterPawn::Move );
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ACharacterPawn::Crouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ACharacterPawn::ResetRot);
	*/
	
}

/*void ACharacterPawn::Move(float Value)
{
	FVector MovementVector = FVector(0, Value * MovementSpeed * GetWorld()->GetDeltaSeconds(),0);
	AddActorLocalOffset(MovementVector, true);
}

void ACharacterPawn::Crouch()
{
	FRotator Target = FRotator(-90,0,0);
	CapsuleComponent->AddLocalRotation(Target);
}

void ACharacterPawn::ResetRot()
{
	CapsuleComponent->AddLocalRotation(FRotator(90,0,0));
}*/