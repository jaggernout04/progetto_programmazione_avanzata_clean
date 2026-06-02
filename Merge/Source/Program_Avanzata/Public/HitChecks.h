// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitChecks.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UHitChecks : public UInterface
{
	GENERATED_BODY()
};

class PROGRAM_AVANZATA_API IHitChecks
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HitChecks")
	bool CheckIsPlayerTeam();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HitChecks")
	float GetDamage();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HitChecks")
	bool CanDamage();
};
