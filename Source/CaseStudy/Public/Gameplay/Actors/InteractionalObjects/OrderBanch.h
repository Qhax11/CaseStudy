// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/InteractionalObjects/InteractionalObject.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"
#include "BaseClasses/GameState_StudyCase.h"
#include "Net/UnrealNetwork.h"
#include "OrderBanch.generated.h"

UENUM(BlueprintType)
enum EOrderState
{
	Start,
	CorrectOrder,
	HalfCorrectOrder,
	WrongOrder
};

UCLASS()
class CASESTUDY_API AOrderBanch : public AInteractionalObject
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay();

	virtual void MakeInteraction(AActor* Player, AOrderObject* OrderObject) override;

	void TryMakePayment(AActor* Player, AOrderObject* OrderObject);

	TEnumAsByte<EOrderState> CheckOrder(AOrderObject* OrderObject);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintImplementableEvent)
	void MakeOrder();

	// Actually "DeterminedOrderObject" and "DeterminedOrderObjectColor" could be struct 
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<AOrderObject> DeterminedOrderObject;

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<EColor> DeterminedOrderObjectColor = EColor::None;

	UPROPERTY(BlueprintReadOnly, Replicated)
	TEnumAsByte<EOrderState> OrderState = EOrderState::Start;

	AGameState_StudyCase* GameState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CorrectOrderReward = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HalfCorrectOrderReward = 50;

};
