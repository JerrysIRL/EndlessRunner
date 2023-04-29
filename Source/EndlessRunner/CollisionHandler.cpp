// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionHandler.h"

#include "EndlessRunnerGameModeBase.h"
#include "ExtendedPawn.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UCollisionHandler::UCollisionHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCollisionHandler::BeginPlay()
{
	Super::BeginPlay();
	Owner = Cast<AExtendedPawn>(GetOwner());
	CurrentHealth = MaxHealthAmount;

	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UCollisionHandler::ActorBeginOverlap);

	// ...
}


// Called every frame
void UCollisionHandler::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UCollisionHandler::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Obstacle")) 
	{
		CurrentHealth -= 1;
		Owner->GameModeRef->SetDodgedWaveBool(false);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("Coin"))
	{
		Owner->GameModeRef->AddToCurrentScore(10);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("MedPack"))
	{
		CurrentHealth += 1;
		OtherActor->Destroy();
	}
	CheckForDeath();
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, 3);
}

void UCollisionHandler::CheckForDeath()
{
	if (CurrentHealth <= 0)
	{
		auto GmRef = Owner->GameModeRef;
		GmRef->SetFinalScore(GmRef->GetScore());
		GmRef->GameOverEvent();
		GetOwner()->Destroy();
	}
}
