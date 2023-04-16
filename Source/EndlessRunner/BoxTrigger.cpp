// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxTrigger.h"

#include "EndlessRunnerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

UBoxTrigger::UBoxTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetGenerateOverlapEvents(true);
}

void UBoxTrigger::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));


	this->OnComponentBeginOverlap.AddDynamic(this, &UBoxTrigger::OnComponentOverlap);
}

void UBoxTrigger::OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Platform"))
	{
		FVector MovePos = GameModeRef->GetSpawningPosition();
		GameModeRef->MovePlatform(OtherActor, MovePos);
	}
}

void UBoxTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);
}
