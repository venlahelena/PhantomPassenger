// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUD/PhantomHUD.h"
#include "Blueprint/UserWidget.h"

void UPhantomHUD::InitializeHUD()
{
	if (InventoryWidgetClass && !InventoryWidget)
	{
		InventoryWidget = CreateWidget<UUserWidget>(GetWorld(), InventoryWidgetClass);
		if (InventoryWidget)
		{
			InventoryWidget->AddToViewport();
			InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UPhantomHUD::UpdateInventory(const TArray<FString>& ItemNames)
{
	// Example: If your InventoryWidget has an exposed function to update items, call it here.
	// You would need to cast InventoryWidget to your actual inventory widget class and call its update method.
	// Example:
	// if (UPhantomInventoryWidget* Widget = Cast<UPhantomInventoryWidget>(InventoryWidget))
	// {
	//     Widget->RefreshItems(ItemNames);
	// }
}

void UPhantomHUD::ShowDialogue(const FString& Speaker, const FString& Text, const TArray<FString>& Choices)
{
    if (!DialogueWidget && DialogueWidgetClass)
    {
        DialogueWidget = CreateWidget<UUserWidget>(GetWorld(), DialogueWidgetClass);
        if (DialogueWidget)
        {
            DialogueWidget->AddToViewport();
        }
    }
    if (DialogueWidget)
    {
        DialogueWidget->SetVisibility(ESlateVisibility::Visible);

        // Example: If your widget has exposed functions, call them here.
        // auto* Widget = Cast<UPhantomDialogueWidget>(DialogueWidget);
        // if (Widget)
        // {
        //     Widget->SetDialogue(Speaker, Text, Choices);
        // }
    }
}

void UPhantomHUD::HideDialogue()
{
    if (DialogueWidget)
    {
        DialogueWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}

