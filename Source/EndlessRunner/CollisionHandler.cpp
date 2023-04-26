// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionHandler.h"


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
	CurrentHealth = MaxHealthAmount;
	//CurrentHealth = FMath::Clamp(CurrentHealth, 0, 2);
	
	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UCollisionHandler::ActorBeginOverlap);
	//GetOwner()->OnActorHit.
	// ...
}


// Called every frame
void UCollisionHandler::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCollisionHandler::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, 2);
	if (OtherActor->ActorHasTag("Obstacle"))
	{
		CurrentHealth -= 1;
		UE_LOG(LogTemp, Warning, TEXT("Current health : %d"), CurrentHealth);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("Coin"))
	{
		CoinsCollected += 1;
		UE_LOG(LogTemp, Warning, TEXT("Coins Collected : %d"), CoinsCollected);
		OtherActor->Destroy();
	}
	if (OtherActor->ActorHasTag("MedPack"))
	{
		CurrentHealth += 1;
		UE_LOG(LogTemp, Warning, TEXT("CurrentH : %d"),CurrentHealth);
		OtherActor->Destroy();
	}
	if (CurrentHealth <= 0)
	{
		GetOwner()->Destroy();
		
	}
}
