// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI/HUD/PhantomHUD.h"
#include "PhantomGameMode.generated.h"

/**
 * Main game mode for Phantom Passenger.
 * Manages global game state and the main HUD widget.
 */
UCLASS()
class PHANTOMPASSENGER_API APhantomGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    APhantomGameMode();

    // Returns the main HUD widget instance
    UFUNCTION(BlueprintCallable, Category = "UI")
    UPhantomHUD* GetPhantomHUD() const;

protected:
    virtual void BeginPlay() override;

    // HUD widget class to spawn
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UPhantomHUD> PhantomHUDWidgetClass;

    // HUD widget instance
    UPROPERTY(BlueprintReadOnly, Category = "UI")
    UPhantomHUD* PhantomHUDInstance;
};
