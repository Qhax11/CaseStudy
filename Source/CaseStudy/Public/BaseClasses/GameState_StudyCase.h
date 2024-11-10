// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "GameState_StudyCase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTotalBudgetChanged, float, TotalBudget);

UCLASS()
class CASESTUDY_API AGameState_StudyCase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnTotalBudgetChanged OnTotalBudgetChanged;

	void AddValueToTotalBudget(float Value);

	UFUNCTION(NetMulticast, Reliable)
	void BrodcastTotalBudget();
	void BrodcastTotalBudget_Implementation();

	UFUNCTION(BlueprintCallable)
	float GetTotalBudget();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:

	UFUNCTION() 
	void OnRep_TotalBudgetVeriable()
	{
		//BrodcastTotalBudget_Implementation();
	}

	UPROPERTY(ReplicatedUsing = OnRep_TotalBudgetVeriable)
	float TotalBudget = 500;

	void SetTotalBudget(float NewTotalBudget);
};
