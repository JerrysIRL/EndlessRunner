// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionHandler.h"

#include "EndlessRunnerGameModeBase.h"
#include "ExtendedPawn.h"
#include "Kismet/GameplayStatics.h"


UCollisionHandler::UCollisionHandler()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCollisionHandler::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = Cast<AExtendedPawn>(GetOwner());
	CurrentHealth = MaxHealthAmount;

	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UCollisionHandler::ActorBeginOverlap);
}

void UCollisionHandler::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCollisionHandler::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Coin"))
	{
		Owner->GameModeRef->AddToCurrentScore(10);
		Owner->GameModeRef->SetDodgedWaveBool(true);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("MedPack"))
	{
		CurrentHealth += 1;
		Owner->GameModeRef->SetDodgedWaveBool(true);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("Obstacle"))
	{
		CurrentHealth -= 1;
		Owner->GameModeRef->SetDodgedWaveBool(false);
		OtherActor->Destroy();
	}
	CheckForDeath();
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, 3);
}

void UCollisionHandler::CheckForDeath() const
{
	if (CurrentHealth <= 0)
	{
		auto GmRef = Owner->GameModeRef;
		GmRef->SetFinalScore(GmRef->GetScore());
		GmRef->GameOverEvent();
		GetOwner()->Destroy();
	}
}
