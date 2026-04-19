#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_GetExperience.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UI_GetExperience : public UInterface
{
	GENERATED_BODY()
};

/* Actual Interface declaration. */
class II_GetExperience
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "I_GetExperience")
	void GetExperience(float Experience);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "I_GetExperience")
	void ApplyUpgrade(UObject* DataObject);
};
