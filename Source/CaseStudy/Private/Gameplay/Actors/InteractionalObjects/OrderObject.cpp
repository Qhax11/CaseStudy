// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "Gameplay/Actors/InteractionalObjects/CarvingMachine.h"
#include "Gameplay/Actors/Player/CaseStudyCharacter.h"

AOrderObject::AOrderObject()
{
	PrimaryActorTick.bCanEverTick = true;
	SetReplicateMovement(true);
	SetReplicates(true);
}

void AOrderObject::BeginPlay()
{
	Super::BeginPlay();

	OwnerCarvingMachine = Cast<ACarvingMachine>(GetOwner());
}

void AOrderObject::Tick(float DeltaSeconds)
{
	if (bAttachToOwnerPlayer && OwnerPlayer)
	{
		FVector NewLocation = OwnerPlayer->GetActorLocation() + OwnerPlayer->GetActorForwardVector() * GrabDistance;
		SetActorLocation(NewLocation, false);
	}
}

void AOrderObject::MakeInteraction(AActor* Player)
{
	TryAttachedToPlayer(Player);
}

void AOrderObject::TryAttachedToPlayer(AActor* Player)
{
	ACaseStudyCharacter* CaseStudyCharacter = Cast<ACaseStudyCharacter>(Player);
	if (!CaseStudyCharacter)
	{
		return;
	}

	if (OwnerCarvingMachine) 
	{
		OwnerCarvingMachine->bMachineIsEmpty = true;
	}

	if (!bAttachToOwnerPlayer)
	{
		OwnerPlayer = CaseStudyCharacter;
		CaseStudyCharacter->SetOrderObject(this);
		bAttachToOwnerPlayer = true;
	}
	else
	{
		OwnerPlayer = nullptr;
		CaseStudyCharacter->SetOrderObject(nullptr);
		bAttachToOwnerPlayer = false;
	}
}
