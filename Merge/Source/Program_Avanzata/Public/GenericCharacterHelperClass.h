// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericCharacterHelperClass.generated.h"

UCLASS()
class PROGRAM_AVANZATA_API AGenericCharacterHelperClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Statistiche (valori correnti)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Armor = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float DamageIncrease = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Speed = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float HealthRegenSecond = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Lifesteal = 0.0f;

	// Valori base (per riferimento / reset)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float MaxHealthBase = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float ArmorBase = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float DamageIncreaseBase = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float SpeedBase = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float HealthRegenSecondBase = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Base")
	float LifestealBase = 0.0f;

	// Livelli (interi)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 MaxHealthLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 ArmorLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 DamageIncreaseLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 SpeedLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 HealthRegenSecondLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats Level")
	int32 LifestealLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IncreaseRates")
	float MaxHealthIncreaseRate = 0.05f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IncreaseRates")
	float DamageIncreaseIncreaseRate = 0.05f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IncreaseRates")
	float SpeedIncreaseRate = 0.05f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPlayerTeam = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDead = false;

	// Sets default values for this character's properties
	AGenericCharacterHelperClass();
	void EventHealthRegen();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float CalculateDamage(float DamageToApply);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ApplyLifesteal(float DamageMade);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void HealCharacter(float HealAmount);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateStats();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateMaxHealth();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateArmor();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateDamage();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateSpeed();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateHealthRegen();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UpdateStats")
	void UpdateLifesteal();

	float CalculateDamage_Implementation(float DamageToApply);
	void ApplyLifesteal_Implementation(float DamageMade);
	void HealCharacter_Implementation(float HealAmount);
	void UpdateStats_Implementation();
	void UpdateMaxHealth_Implementation();
	void UpdateArmor_Implementation();
	void UpdateDamage_Implementation();
	void UpdateSpeed_Implementation();
	void UpdateHealthRegen_Implementation();
	void UpdateLifesteal_Implementation();


protected:


	FTimerHandle HealthRegenTimerHandle;

	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;
};