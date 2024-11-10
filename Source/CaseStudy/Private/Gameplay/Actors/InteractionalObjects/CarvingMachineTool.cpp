// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/CarvingMachineTool.h"

void ACarvingMachineTool::MakeInteraction()
{
	BrodcastWillBeCreatedOrderObjectChanged();
}

void ACarvingMachineTool::BrodcastWillBeCreatedOrderObjectChanged()
{
	OnWillBeCreatedOrderObjectChanged.Broadcast(RepresentativeOrderObject);
}
