// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ARPGPlayerState.generated.h"

/**
 *
 */
UCLASS()
class ARPG_API AARPGPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	/** Player Status */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		int CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		int SkillPoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		int StrengthValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		int DexterityValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		int IntellectValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float PlayerHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float PlayerMaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float PlayerArmor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float PlayerMaxArmor;
};
