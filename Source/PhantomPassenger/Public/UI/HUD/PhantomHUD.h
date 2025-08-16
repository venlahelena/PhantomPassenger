// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhantomHUD.generated.h"

class UUserWidget;

/**
 * Main HUD widget for Phantom Passenger.
 * Manages always-on inventory and other UI panels.
 */
UCLASS()
class PHANTOMPASSENGER_API UPhantomHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "UI")
	void InitializeHUD();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateInventory(const TArray<FString>& ItemNames);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowDialogue(const FString& Speaker, const FString& Text, const TArray<FString>& Choices);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideDialogue();

	UFUNCTION(BlueprintCallable)
	void HideInteractionMenu();

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUserWidget* InventoryWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUserWidget* DialogueWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> DialogueWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> InteractionMenuWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUserWidget* InteractionMenuWidget;
};
