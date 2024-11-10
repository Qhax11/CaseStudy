// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "PaintBox.generated.h"

/**
 * 
 */
UCLASS()
class CASESTUDY_API APaintBox : public AInteractionalObject
{
	GENERATED_BODY()
	
public:
	virtual void MakeInteraction() override;

	UFUNCTION(NetMulticast, Reliable)
	void ChanceColorOfOrderObject();
	void ChanceColorOfOrderObject_Implementation();

	AOrderObject* WillBePaintObjectOrder;

private:
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EColor> PaintBoxColor;

};
