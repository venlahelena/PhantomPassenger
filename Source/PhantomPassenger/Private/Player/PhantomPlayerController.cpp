// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/PhantomPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "UI/HUD/PhantomHUD.h"
#include "Characters/PassangerCharacter.h"
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
    FVector2D MousePosition;
    if (GetMousePosition(MousePosition.X, MousePosition.Y))
    {
        FHitResult HitResult;
        // Perform a line trace from the mouse position into the world
        if (GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, false, HitResult))
        {
            if (AActor* HitActor = HitResult.GetActor())
            {
                UE_LOG(LogTemp, Warning, TEXT("Line trace hit actor: %s"), *HitActor->GetName());

                // Check if the hit actor is a passenger
                APassangerCharacter* Passenger = Cast<APassangerCharacter>(HitActor);
                if (Passenger)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Passenger clicked: %s"), *Passenger->GetName());
                    Passenger->PassengerClickedEvent(); // Pass index if you have it, or -1
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Clicked actor is not a passenger: %s"), *HitActor->GetName());
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Line trace did not hit any actor."));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("No actor hit by line trace."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not get mouse position."));
    }
}

void APhantomPlayerController::OnOpenNotebook(const FInputActionValue& Value)
{
    // Handle notebook opening logic here
}

