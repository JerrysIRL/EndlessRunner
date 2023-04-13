// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxTrigger.h"

UBoxTrigger::UBoxTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBoxTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void UBoxTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);
	for (auto Actor : OverlappingActors)
	{
		//if(Actor->ActorHasTag("Platform"))

		UE_LOG(LogTemp, Warning, TEXT("Collided with the Platform: %s"), *Actor->GetActorNameOrLabel());
	}
}

