// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseClasses/GameState_StudyCase.h"


void AGameState_StudyCase::AddValueToTotalBudget(float Value)
{
	SetTotalBudget(TotalBudget + Value);
	BrodcastTotalBudget_Implementation();
}

void AGameState_StudyCase::BrodcastTotalBudget_Implementation()
{
	// The Multicast doesen't work, idk why? if it's worked i could use in HUD
	OnTotalBudgetChanged.Broadcast(TotalBudget);
}

float AGameState_StudyCase::GetTotalBudget()
{
	return TotalBudget;
}

void AGameState_StudyCase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGameState_StudyCase, TotalBudget);
}

void AGameState_StudyCase::SetTotalBudget(float NewTotalBudget)
{
	TotalBudget = NewTotalBudget;
}
