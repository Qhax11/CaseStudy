// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "Gameplay/Actors/InteractionalObjects/CarvingMachine.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "CarvingMachineTool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWillBeCreatedOrderObjectChanged, TSubclassOf<AOrderObject>, OrderObject);

UCLASS()
class CASESTUDY_API ACarvingMachineTool : public AInteractionalObject
{
	GENERATED_BODY()
	
public:
	virtual void MakeInteraction() override;

	void BrodcastWillBeCreatedOrderObjectChanged();

	FOnWillBeCreatedOrderObjectChanged OnWillBeCreatedOrderObjectChanged;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AOrderObject> RepresentativeOrderObject;
};
