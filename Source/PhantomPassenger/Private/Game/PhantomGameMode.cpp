// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PhantomGameMode.h"
#include "Player/PlayerPawn.h"
#include "Player/PhantomPlayerController.h"

APhantomGameMode::APhantomGameMode()
{
    DefaultPawnClass = APlayerPawn::StaticClass();
    PlayerControllerClass = APhantomPlayerController::StaticClass();

    PhantomHUDWidgetClass = nullptr;
    PhantomHUDInstance = nullptr;
}

void APhantomGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (PhantomHUDWidgetClass)
    {
        PhantomHUDInstance = CreateWidget<UPhantomHUD>(GetWorld(), PhantomHUDWidgetClass);
        if (PhantomHUDInstance)
        {
            PhantomHUDInstance->AddToViewport();
            PhantomHUDInstance->InitializeHUD();
        }
    }
}

UPhantomHUD* APhantomGameMode::GetPhantomHUD() const
{
    return PhantomHUDInstance;
}
