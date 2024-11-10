// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/InteractionalObjects/PaintBench.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/Actors/InteractionalObjects/OrderObject.h"

APaintBench::APaintBench()
{
	LocationOrderObject = CreateDefaultSubobject<UArrowComponent>(TEXT("LocationOrderObject"));
}

void APaintBench::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundPaintBoxes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APaintBox::StaticClass(), FoundPaintBoxes);

	for (AActor* CollectedActor : FoundPaintBoxes)
	{
		APaintBox* FoundPaintBox = Cast<APaintBox>(CollectedActor);
		CastedFoundPaintBoxes.Add(FoundPaintBox);
	}
}

void APaintBench::MakeInteraction(AOrderObject* OrderObject)
{
	PutOrderObjectToBench(OrderObject);
}

void APaintBench::PutOrderObjectToBench(AOrderObject* OrderObject)
{
	if (!OrderObject)
	{
		return;
	}

	OrderObject->bAttachToOwnerPlayer = false;
	OrderObject->SetActorLocation(LocationOrderObject->GetComponentLocation());

	SetOrderObjectToPaintBoxes(OrderObject);
}

void APaintBench::SetOrderObjectToPaintBoxes_Implementation(AOrderObject* OrderObject)
{
	for (APaintBox* CastedPaintBox : CastedFoundPaintBoxes)
	{
		CastedPaintBox->WillBePaintObjectOrder = OrderObject;
	}
}
