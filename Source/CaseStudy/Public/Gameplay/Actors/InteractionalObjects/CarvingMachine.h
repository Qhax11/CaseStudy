// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "Components/ArrowComponent.h"
#include "CarvingMachine.generated.h"


UCLASS()
class CASESTUDY_API ACarvingMachine : public AInteractionalObject
{
	GENERATED_BODY()
	
public:
	ACarvingMachine();

	virtual void BeginPlay() override;

	virtual void MakeInteraction() override;

	void TryCreateOrderObject();

	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* LocationOrderObject;

	bool bMachineIsEmpty = true;
protected:

	UFUNCTION()
	void WillBeCreatedOrderObjectChanged(TSubclassOf<AOrderObject> NewOrderObject);

	// For Blueprint, UI
	UFUNCTION(BlueprintImplementableEvent)
	void OnWillBeCreatedOrderObjectChangedChanged(TSubclassOf<AOrderObject> NewOrderObject);

	void SpawnOrderObject(TSubclassOf<AOrderObject> OrderObject);

private:

	TSubclassOf<AOrderObject> SelectedOrderObject = nullptr;
};
