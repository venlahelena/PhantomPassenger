// Fill out your copyright notice in the Description page of Project Settings.


#include "Bus/BusManager.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/PassangerCharacter.h"
#include "Engine/World.h"

ABusManager::ABusManager()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentStop = 0;
    TotalStops = 5;
    BusInfo.RouteNumber = FMath::RandRange(100, 999);
    BusInfo.Date = FDateTime::Now() + FTimespan(FMath::RandRange(-5, 5), 0, 0, 0);
    BusInfo.Time = FDateTime::Now() + FTimespan(0, FMath::RandRange(0, 120), 0);
    BusInfo.BusNumber = FMath::RandRange(1, 20);
}

void ABusManager::BeginPlay()
{
    Super::BeginPlay();

    SpawnPassengers();
    AssignTruthItem();
}

void ABusManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


void ABusManager::RandomizeBusInfo()
{
    BusInfo.RouteNumber = FMath::RandRange(100, 999);
    BusInfo.Date = FDateTime::Now() + FTimespan(FMath::RandRange(-5, 5), 0, 0, 0);
    BusInfo.Time = FDateTime::Now() + FTimespan(0, FMath::RandRange(0, 120), 0);
    BusInfo.BusNumber = FMath::RandRange(1, 20);
}

void ABusManager::SpawnPassengers()
{
    PassengerActors.Empty();

    int32 NumPassengers = FMath::RandRange(5, 7);
    int32 PhantomIndex = FMath::RandRange(0, NumPassengers - 1);

    UWorld* World = GetWorld();
    if (!World || !PassengerClass) return;

    for (int32 i = 0; i < NumPassengers; ++i)
    {
        // Example positions
        // later need logic that eahc character i swpaned spesiifc seat in the bus.
        FVector SpawnLocation(100.f * i, 0.f, 100.f);
        FRotator SpawnRotation = FRotator::ZeroRotator;

        APassangerCharacter* NewPassenger = World->SpawnActor<APassangerCharacter>(PassengerClass, SpawnLocation, SpawnRotation);

        if (NewPassenger)
        {
            bool bAssignPhantom = (i == PhantomIndex);
            NewPassenger->RandomizePassenger(
                bAssignPhantom,
                CurrentStop,
                BusInfo.Date.ToString(TEXT("%Y-%m-%d")),
                FString::FromInt(BusInfo.RouteNumber)
            );
            PassengerActors.Add(NewPassenger);
        }
    }
}

void ABusManager::AssignTruthItem()
{
    Items.Empty();
    TArray<FString> ItemNames = { TEXT("Candy"), TEXT("Charm"), TEXT("Book"), TEXT("Flower") };
    int32 TruthIndex = FMath::RandRange(0, ItemNames.Num() - 1);

    for (int i = 0; i < ItemNames.Num(); ++i)
    {
        FItem NewItem;
        NewItem.ItemName = ItemNames[i];
        NewItem.bIsTruthItem = (i == TruthIndex);
        Items.Add(NewItem);
    }
}

void ABusManager::AdvanceToNextStop()
{
    if (CurrentStop < TotalStops)
    {
        ++CurrentStop;
        // Optionally board new passengers or trigger summary UI
    }
    else
    {
        TriggerDeduction();
    }
}

void ABusManager::TriggerDeduction()
{
    // Evaluate clues and player selection
    // Trigger success/fail ending (stub)
}

void ABusManager::OnPassengerClicked(int32 PassengerIndex)
{
    // Open interaction menu for the selected passenger (stub)
}

void ABusManager::InspectTicket(int32 PassengerIndex)
{
    if (!PassengerActors.IsValidIndex(PassengerIndex)) return;
    const APassangerCharacter* Passenger = PassengerActors[PassengerIndex];
    const FPassengerTicket& Ticket = Passenger->Ticket;

    FString Clue;
    if (Ticket.RouteNumber != FString::FromInt(BusInfo.RouteNumber))
        Clue += TEXT("Route mismatch. ");
    if (Ticket.Date != BusInfo.Date.ToString(TEXT("%Y-%m-%d")))
        Clue += TEXT("Date mismatch. ");
    // Time comparison can be added if it is needed

    if (!Clue.IsEmpty())
        LogClue(FString::Printf(TEXT("Passenger %d: %s"), PassengerIndex, *Clue));
}

void ABusManager::OfferItemToPassenger(int32 PassengerIndex, int32 ItemIndex)
{
    if (!PassengerActors.IsValidIndex(PassengerIndex) || !Items.IsValidIndex(ItemIndex)) return;
    const APassangerCharacter* Passenger = PassengerActors[PassengerIndex];
    const FItem& Item = Items[ItemIndex];

    FString Clue;
    if (Item.bIsTruthItem && Passenger->bIsPhantom)
        Clue = TEXT("Supernatural reaction! Major clue.");
    else if (Item.bIsTruthItem)
        Clue = TEXT("No reaction.");
    else
        Clue = TEXT("Minor feedback.");

    LogClue(FString::Printf(TEXT("Passenger %d, Item %s: %s"), PassengerIndex, *Item.ItemName, *Clue));
}

void ABusManager::ObservePassenger(int32 PassengerIndex)
{
    if (!PassengerActors.IsValidIndex(PassengerIndex)) return;
    const APassangerCharacter* Passenger = PassengerActors[PassengerIndex];
    LogClue(FString::Printf(TEXT("Observed Passenger %d: %s"), PassengerIndex, *UEnum::GetValueAsString(Passenger->Archetype)));
}

void ABusManager::LogClue(const FString& Clue)
{
    Notebook.Add(Clue);
}