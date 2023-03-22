// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGPlayerController.h"
#include <EnhancedInputComponent.h>
#include "GameFramework/Character.h"
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "MyInputConfigData.h"
#include "ARPGCharacter.h"


void AARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//ConstructorHelpers::FObjectFinder<UInputMappingContext>mc(TEXT("Game/ThirdPerson/Input/IMC_Default.uasset"));
	FSoftObjectPath assetRef("/Script/EnhancedInput.InputMappingContext'/Game/ThirdPerson/Input/IMC_Default.IMC_Default'");
	//DefaultMappingContext = mc.Object;
	// Get the local player subsystem
	DefaultMappingContext = Cast< UInputMappingContext>(assetRef.TryLoad());
	if (DefaultMappingContext != nullptr)
	{
	}
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{

		// Clear out existing mapping, and add our mapping
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	FSoftObjectPath actionRef("/ Script / ARPG.MyInputConfigData'/Game/ThirdPerson/Input/ActionConfigs.ActionConfigs'");
	InputActions = Cast< UMyInputConfigData>(actionRef.TryLoad());


	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(InputActions->InputJump, ETriggerEvent::Triggered, this, &AARPGPlayerController::Jump);
		EnhancedInputComponent->BindAction(InputActions->InputJump, ETriggerEvent::Completed, this, &AARPGPlayerController::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AARPGPlayerController::Move);

		//Looking
		EnhancedInputComponent->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &AARPGPlayerController::Look);

		//Sprinting
		EnhancedInputComponent->BindAction(InputActions->InputSprint, ETriggerEvent::Triggered, this, &AARPGPlayerController::Sprint);
		EnhancedInputComponent->BindAction(InputActions->InputSprint, ETriggerEvent::Completed, this, &AARPGPlayerController::StopSprinting);

	}
}

void AARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();


	
}

void AARPGPlayerController::Jump()
{
	GetCharacter()->Jump();

	if (ACharacter* character = GetCharacter())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));

	}
}
void AARPGPlayerController::StopJumping()
{
	GetCharacter()->StopJumping();

	if (ACharacter* character = Cast<ACharacter>(GetPawn()))
	{
	}
}

void AARPGPlayerController::Move(const FInputActionValue& Value)
{
	if (AARPGCharacter* aCharacter = Cast<AARPGCharacter>(GetCharacter()))
	{
		aCharacter->Move(Value);
	}
}

void AARPGPlayerController::Look(const FInputActionValue& Value)
{
	if (AARPGCharacter* aCharacter = Cast<AARPGCharacter>(GetCharacter()))
	{
		aCharacter->Look(Value);
	}
}

void AARPGPlayerController::Sprint()
{
	if (AARPGCharacter* aCharacter = Cast<AARPGCharacter>(GetCharacter()))
	{
		aCharacter->Sprint();
	}
}

void AARPGPlayerController::StopSprinting()
{
	if (AARPGCharacter* aCharacter = Cast<AARPGCharacter>(GetCharacter()))
	{
		aCharacter->StopSprinting();
	}
}

