// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Components/AC_MakeInteractionAbility.h"
#include "Gameplay/Interface/InteractionInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UAC_MakeInteractionAbility::UAC_MakeInteractionAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UAC_MakeInteractionAbility::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ACaseStudyCharacter>(GetOwner());
}

void UAC_MakeInteractionAbility::ActivateAbility()
{
	LineTrace();
}

void UAC_MakeInteractionAbility::LineTrace()
{
	if (!PlayerCharacter) 
	{
		return;
	}

	FVector EyesViewPoint;
	FRotator EyesViewRot;
	FHitResult HitResult;

	PlayerCharacter->GetController()->GetActorEyesViewPoint(EyesViewPoint, EyesViewRot);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(EyesViewRot) * 1000;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(PlayerCharacter);

	GetWorld()->LineTraceSingleByChannel(HitResult, EyesViewPoint, EyesViewPoint + ForwardVector, ECollisionChannel::ECC_WorldDynamic, QueryParams);

	DrawDebugLine(
		GetWorld(),
		EyesViewPoint,
		EyesViewPoint + ForwardVector,
		FColor::Black,
		false,
		LineTraceDebugDuration,
		0,
		2.0f
	);

	MakeInteraction(HitResult.GetActor());
}

void UAC_MakeInteractionAbility::MakeInteraction_Implementation(AActor* HitActor)
{
	if (IInteractionInterface* InteractionInterface = Cast<IInteractionInterface>(HitActor))
	{
		// Calling all overloads because every entity implement different one
		InteractionInterface->MakeInteraction(PlayerCharacter, PlayerCharacter->GetOrderObject());
		InteractionInterface->MakeInteraction(PlayerCharacter);
		InteractionInterface->MakeInteraction(PlayerCharacter->GetOrderObject());
		InteractionInterface->MakeInteraction();
	}
}

