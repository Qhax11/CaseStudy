// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/PaintBox.h"


void APaintBox::MakeInteraction()
{
	ChanceColorOfOrderObject();
}

void APaintBox::ChanceColorOfOrderObject_Implementation()
{
	if (WillBePaintObjectOrder) 
	{
		WillBePaintObjectOrder->InteractionalObjectMesh->SetMaterial(0, InteractionalObjectMesh->GetMaterial(0));
		WillBePaintObjectOrder->OrderObjectColor = PaintBoxColor;
	}
}




