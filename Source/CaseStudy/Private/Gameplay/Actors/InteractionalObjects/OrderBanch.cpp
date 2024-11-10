// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/OrderBanch.h"
#include "Gameplay/Actors/Player/CaseStudyCharacter.h"

void AOrderBanch::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AGameState_StudyCase>(GetWorld()->GetGameState());
}

void AOrderBanch::MakeInteraction(AActor* Player, AOrderObject* OrderObject)
{
	TryMakePayment(Player, OrderObject);
	if (OrderObject) 
	{
		MakeOrder();
	}
}

void AOrderBanch::TryMakePayment(AActor* Player, AOrderObject* OrderObject)
{
	if (!OrderObject || !Player->HasAuthority())
	{
		return;
	}

	ACaseStudyCharacter* CaseStudyCharacter = Cast<ACaseStudyCharacter>(Player);
	if (!CaseStudyCharacter)
	{
		return;
	}

	if (CheckOrder(OrderObject) == EOrderState::CorrectOrder)
	{
		GameState->AddValueToTotalBudget(CorrectOrderReward);
	}
	else if (CheckOrder(OrderObject) == EOrderState::HalfCorrectOrder)
	{
		GameState->AddValueToTotalBudget(HalfCorrectOrderReward);
	}

	OrderObject->Destroy();
	// Why it didn't become nullptr automatically
	CaseStudyCharacter->SetOrderObject(nullptr);
}

TEnumAsByte<EOrderState> AOrderBanch::CheckOrder(AOrderObject* OrderObject)
{
	if (OrderObject->GetClass() == DeterminedOrderObject && OrderObject->OrderObjectColor == DeterminedOrderObjectColor)
	{
		OrderState = EOrderState::CorrectOrder;
	}
	else if (OrderObject->GetClass() == DeterminedOrderObject && OrderObject->OrderObjectColor != DeterminedOrderObjectColor)
	{
		OrderState = EOrderState::HalfCorrectOrder;
	}
	else
	{
		OrderState = EOrderState::WrongOrder;
	}
	return OrderState;
}

void AOrderBanch::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AOrderBanch, OrderState);
}
