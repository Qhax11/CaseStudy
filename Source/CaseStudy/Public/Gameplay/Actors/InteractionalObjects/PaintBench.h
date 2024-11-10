// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "Gameplay/Actors/InteractionalObjects/PaintBox.h"
#include "Components/ArrowComponent.h"
#include "PaintBench.generated.h"

/**
 * 
 */
UCLASS()
class CASESTUDY_API APaintBench : public AInteractionalObject
{
	GENERATED_BODY()

public:
	APaintBench();

	virtual void BeginPlay() override;

	virtual void MakeInteraction(AOrderObject* OrderObject) override;

	void PutOrderObjectToBench(AOrderObject* OrderObject);

	UFUNCTION(NetMulticast, Reliable)
	void SetOrderObjectToPaintBoxes(AOrderObject* OrderObject);
	void SetOrderObjectToPaintBoxes_Implementation(AOrderObject* OrderObject);

private:
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* LocationOrderObject;

	TArray<APaintBox*> CastedFoundPaintBoxes;
};
