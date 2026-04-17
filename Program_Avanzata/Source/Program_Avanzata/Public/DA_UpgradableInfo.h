// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_UpgradableInfo.generated.h"

/**
 * 
 */
USTRUCT()
struct FUpgradableInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    FString Name;

    UPROPERTY(EditAnywhere)
    FString Description;

    UPROPERTY(EditAnywhere)
    UTexture2D* Thumbnail;

};


UCLASS()
class PROGRAM_AVANZATA_API UDA_UpgradableInfo : public UDataAsset
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    TArray<FUpgradableInfo> UpgradableInfo;

};
