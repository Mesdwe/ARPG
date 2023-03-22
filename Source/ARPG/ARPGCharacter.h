// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ARPGCharacter.generated.h"


UCLASS(config=Game)
class AARPGCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	


public:
	AARPGCharacter();
	
protected:
	bool bIsSprinting;


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

	UPROPERTY()
		class AARPGPlayerState* ARPGPlayerState;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UPlayerHUD> PlayerHUDClass;

	UPROPERTY()
		class UPlayerHUD* PlayerHUD;


public:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	//Allows the character to begin sprinting
	void Sprint();

	//Allows the character to stop sprinting
	void StopSprinting();

	//Allows the character to take damage
	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(float damageAmount);

	//Allows the character to heal
	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float healAmount);


	UFUNCTION(BlueprintCallable, Category = "Health")
	void HealArmor(float recoverAmount);



protected:
	// APawn interface
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float deltaSeconds);

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

