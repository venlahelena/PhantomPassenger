// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhantomPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UPhantomHUD;

struct FInputActionValue;

UCLASS()
class PHANTOMPASSENGER_API APhantomPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    APhantomPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    // Enhanced Input references
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* PhantomMappingContext;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputAction* InteractAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputAction* OpenNotebookAction;

    void OnInteract(const FInputActionValue& Value);
    void OnOpenNotebook(const FInputActionValue& Value);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UPhantomHUD> PhantomHUDWidgetClass;
};
