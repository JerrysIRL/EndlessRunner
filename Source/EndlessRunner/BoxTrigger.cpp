// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxTrigger.h"

UBoxTrigger::UBoxTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetGenerateOverlapEvents(true);
}

void UBoxTrigger::BeginPlay()
{
	Super::BeginPlay();
	this->OnComponentBeginOverlap.AddDynamic(this, &UBoxTrigger::OnComponentOverlap);
}

void UBoxTrigger::OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor::Red,(TEXT("On Component Overlap Begin!")));
	UE_LOG(LogTemp, Warning, TEXT("Collided with the Platform:"));

}

void UBoxTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);
	// for (auto Actor : OverlappingActors)
	// {
	// 	if (Actor->ActorHasTag("Platform"))
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("Collided with the Platform: %s"), *Actor->GetActorNameOrLabel());
	// 	}
	// }
}
