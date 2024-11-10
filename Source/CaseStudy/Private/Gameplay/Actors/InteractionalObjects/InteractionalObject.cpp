// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"

// Sets default values
AInteractionalObject::AInteractionalObject()
{
	PrimaryActorTick.bCanEverTick = false;

	InteractionalObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InteractionalObjectMesh"));
	InteractionalObjectMesh->SetIsReplicated(true);
}

void AInteractionalObject::MakeInteraction(AActor* Player, AOrderObject* OrderObject)
{
	// Logic will be in subclasses
}

