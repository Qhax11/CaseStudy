// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/CarvingMachine.h"
#include "Gameplay/Actors/Player/CaseStudyCharacter.h"
#include "Gameplay/Actors/InteractionalObjects/CarvingMachineTool.h"
#include "Kismet/GameplayStatics.h"


ACarvingMachine::ACarvingMachine()
{
	LocationOrderObject = CreateDefaultSubobject<UArrowComponent>(TEXT("LocationOrderObject"));
}

void ACarvingMachine::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundCarvingMachineTools;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACarvingMachineTool::StaticClass(), FoundCarvingMachineTools);

	// We listen changing of WillBeCreatedOrderObject from all CarvingMachineTools
	for (AActor* CollectedActor : FoundCarvingMachineTools)
	{
		ACarvingMachineTool* FoundCarvingMachineTool = Cast<ACarvingMachineTool>(CollectedActor);
		FoundCarvingMachineTool->OnWillBeCreatedOrderObjectChanged.AddDynamic(this, &ACarvingMachine::WillBeCreatedOrderObjectChanged);
	}
}

void ACarvingMachine::MakeInteraction()
{
	TryCreateOrderObject();
}

void ACarvingMachine::TryCreateOrderObject()
{
	if (!bMachineIsEmpty)
	{
		UE_LOG(LogTemp, Warning, TEXT("You have to take created one!"));
	}
	else
	{
		SpawnOrderObject(SelectedOrderObject);
	}
}

void ACarvingMachine::WillBeCreatedOrderObjectChanged(TSubclassOf<AOrderObject> NewOrderObject)
{
	SelectedOrderObject = NewOrderObject;
	OnWillBeCreatedOrderObjectChangedChanged(NewOrderObject);
}

void ACarvingMachine::SpawnOrderObject(TSubclassOf<AOrderObject> OrderObject)
{
	if (!OrderObject) 
	{
		return ;
	}

	// It not empyt anymore, OrderObject is created!
	bMachineIsEmpty = false;

	FActorSpawnParameters Params;
	Params.Owner = this;
	GetWorld()->SpawnActor<AActor>(OrderObject, LocationOrderObject->GetComponentLocation(), FRotator(), Params);
}

