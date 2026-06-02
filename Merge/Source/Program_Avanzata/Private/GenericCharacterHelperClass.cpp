// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericCharacterHelperClass.h"

// Sets default values
AGenericCharacterHelperClass::AGenericCharacterHelperClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGenericCharacterHelperClass::BeginPlay()
{
	Super::BeginPlay();
	EventHealthRegen();
	UpdateStats();
	CurrentHealth = MaxHealth;
}

void AGenericCharacterHelperClass::EventHealthRegen()
{

	HealCharacter(HealthRegenSecond);
	GetWorldTimerManager().SetTimer(
		HealthRegenTimerHandle,
		this,
		&AGenericCharacterHelperClass::EventHealthRegen,
		1.0f,
		!IsDead
	);
}



float AGenericCharacterHelperClass::CalculateDamage_Implementation(float DamageToApply)
{
	float ArmourReductionConstant = 100.0f;
	float LocalHealth = 0.0f;
	float FinalDamage = 0.0f;

	if (!IsDead && CurrentHealth <= 0.0f)
	{
		IsDead = true;
		CurrentHealth = -1.0f;
		return -1.0f; // Character is already dead, return -1 to indicate no damage applied
	}

	float ArmourReduction = 1 + (Armor / ArmourReductionConstant);
	FinalDamage = DamageToApply / ArmourReduction;
	LocalHealth = CurrentHealth - FinalDamage;
	if (LocalHealth <= 0.0f)
	{
		LocalHealth = -1.0f;
		IsDead = true;
	}

	CurrentHealth = LocalHealth;

	return FinalDamage;
}

void AGenericCharacterHelperClass::HealCharacter_Implementation(float HealAmount)
{
	CurrentHealth += HealAmount;
	if (CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void AGenericCharacterHelperClass::ApplyLifesteal_Implementation(float DamageMade)
{
	HealCharacter(DamageMade * Lifesteal);
}

void AGenericCharacterHelperClass::UpdateStats_Implementation()
{
	UpdateMaxHealth();
	UpdateArmor();
	UpdateDamage();
	UpdateSpeed();
	UpdateHealthRegen();
	UpdateLifesteal();
}


void AGenericCharacterHelperClass::UpdateMaxHealth_Implementation()
{
	float CurrentHealthPercent = CurrentHealth / MaxHealth;

	MaxHealth = MaxHealthBase + (MaxHealthBase * (float)MaxHealthLevel * MaxHealthIncreaseRate);
}

void AGenericCharacterHelperClass::UpdateArmor_Implementation()
{
	Armor = ArmorBase + (ArmorBase * (float)ArmorLevel);
}

void AGenericCharacterHelperClass::UpdateDamage_Implementation()
{
	DamageIncrease = DamageIncreaseBase + (DamageIncreaseBase * (float)DamageIncreaseLevel * DamageIncreaseIncreaseRate);
}

void AGenericCharacterHelperClass::UpdateSpeed_Implementation()
{
	Speed = SpeedBase + (SpeedBase * (float)SpeedLevel * SpeedIncreaseRate);
}

void AGenericCharacterHelperClass::UpdateHealthRegen_Implementation()
{
	HealthRegenSecond = HealthRegenSecondBase + (2 * (float)HealthRegenSecondLevel);
}

void AGenericCharacterHelperClass::UpdateLifesteal_Implementation()
{
	Lifesteal = LifestealBase + (0.05f * (float)LifestealLevel);
}
