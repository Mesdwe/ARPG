// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "ARPGPlayerController.generated.h"
/**
 *
 */
UCLASS()
class ARPG_API AARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UMyInputConfigData* InputActions;



protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	void Jump();
	void StopJumping();
	/** Called for movement input */
	void Move(const FInputActionValue& Value);
	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	//Allows the character to begin sprinting
	void Sprint();

	//Allows the character to stop sprinting
	void StopSprinting();

};
