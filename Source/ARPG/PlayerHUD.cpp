// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Components/ProgressBar.h"

void UPlayerHUD::SetHealth(float currentHealth, float maxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(currentHealth / maxHealth);
	}
}

void UPlayerHUD::SetArmor(float currentStamina, float maxStamina)
{
	if (StaminaBar)
	{
		StaminaBar->SetPercent(currentStamina / maxStamina);
	}
}
