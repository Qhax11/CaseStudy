#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

class AOrderObject;

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};


class IInteractionInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	virtual void MakeInteraction(AActor* Player, AOrderObject* OrderObject) {}

	virtual void MakeInteraction(AActor* Player) {}

	virtual void MakeInteraction(AOrderObject* OrderObject) {}

	virtual void MakeInteraction() {}

};
