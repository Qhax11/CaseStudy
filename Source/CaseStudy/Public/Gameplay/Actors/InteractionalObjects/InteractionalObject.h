// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Interface/InteractionInterface.h"
#include "InteractionalObject.generated.h"

UCLASS()
class CASESTUDY_API AInteractionalObject : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionalObject();

	virtual void MakeInteraction(AActor* Player, AOrderObject* OrderObject);

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* InteractionalObjectMesh;

};
