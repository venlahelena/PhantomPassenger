// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PhantomPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "UI/HUD/PhantomHUD.h"
#include "Blueprint/UserWidget.h"

APhantomPlayerController::APhantomPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void APhantomPlayerController::BeginPlay()
{
    Super::BeginPlay();

     UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
     if (Subsystem && PhantomMappingContext)
     {
         Subsystem->AddMappingContext(PhantomMappingContext, 0);
     }

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);

    if (PhantomHUDWidgetClass)
    {
        UPhantomHUD* HUDWidget = CreateWidget<UPhantomHUD>(this, PhantomHUDWidgetClass);
        if (HUDWidget)
        {
            HUDWidget->AddToViewport();
            HUDWidget->InitializeHUD();
        }
    }
}

void APhantomPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

     UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
     if (EnhancedInput)
     {

        EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APhantomPlayerController::OnInteract);
        EnhancedInput->BindAction(OpenNotebookAction, ETriggerEvent::Started, this, &APhantomPlayerController::OnOpenNotebook);
     }
}

void APhantomPlayerController::OnInteract(const FInputActionValue& Value)
{
    // Handle interaction logic here
}

void APhantomPlayerController::OnOpenNotebook(const FInputActionValue& Value)
{
    // Handle notebook opening logic here
}

