// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Actors/Player/CaseStudyCharacter.h"
#include "AC_MakeInteractionAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASESTUDY_API UAC_MakeInteractionAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_MakeInteractionAbility();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	void ActivateAbility();

	void LineTrace();

	class ACaseStudyCharacter* PlayerCharacter;

	UFUNCTION(Server, Reliable)
	void MakeInteraction(AActor* HitActor);
	void MakeInteraction_Implementation(AActor* HitActor);

	UPROPERTY(EditDefaultsOnly)
	float LineTraceDebugDuration = 2.0f;
};
