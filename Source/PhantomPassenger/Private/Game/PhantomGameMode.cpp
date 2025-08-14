// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PhantomGameMode.h"
#include "Player/PlayerPawn.h"
#include "Player/PhantomPlayerController.h"

APhantomGameMode::APhantomGameMode()
{
    DefaultPawnClass = APlayerPawn::StaticClass();
    PlayerControllerClass = APhantomPlayerController::StaticClass();
}
