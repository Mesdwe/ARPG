// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInput/Public/InputAction.h"
#include "MyInputConfigData.generated.h"
/**
 * 
 */
UCLASS()
class ARPG_API UMyInputConfigData : public UDataAsset
{
	GENERATED_BODY()


public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputMove;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputLook;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputJump;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputSprint;
};
