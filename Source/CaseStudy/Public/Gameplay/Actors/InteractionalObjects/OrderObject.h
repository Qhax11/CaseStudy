// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "OrderObject.generated.h"

UENUM(BlueprintType)
enum EColor
{
	None,
	Red,
	Green,
	Blue
};


UCLASS()
class CASESTUDY_API AOrderObject : public AInteractionalObject
{
	GENERATED_BODY()
	
public:
	AOrderObject();

	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds);

	virtual void MakeInteraction(AActor* Player) override;

	void TryAttachedToPlayer(AActor* Player);

	bool bAttachToOwnerPlayer = false;

	TEnumAsByte<EColor> OrderObjectColor = EColor::None;
private:
	AActor* OwnerPlayer;

	class ACarvingMachine* OwnerCarvingMachine;

	UPROPERTY(EditDefaultsOnly, Category = "OrderObject")
	float GrabDistance = 200;
};
