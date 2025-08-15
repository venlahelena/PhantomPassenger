#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BusManager.generated.h"

class APassangerCharacter;

USTRUCT(BlueprintType)
struct FBusInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RouteNumber;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FDateTime Date;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FDateTime Time;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BusNumber;
};

USTRUCT(BlueprintType)
struct FItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsTruthItem;
};

UCLASS()
class PHANTOMPASSENGER_API ABusManager : public AActor
{
    GENERATED_BODY()

public:
    ABusManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FBusInfo BusInfo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentStop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TotalStops;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<APassangerCharacter*> PassengerActors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<APassangerCharacter> PassengerClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FItem> Items;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Notebook;

    // Core logic
    void RandomizeBusInfo();
    void SpawnPassengers();
    void AssignTruthItem();
    void AdvanceToNextStop();
    void TriggerDeduction();

    // UI/Interaction
    void OnPassengerClicked(int32 PassengerIndex);
    void InspectTicket(int32 PassengerIndex);
    void OfferItemToPassenger(int32 PassengerIndex, int32 ItemIndex);
    void ObservePassenger(int32 PassengerIndex);
    void LogClue(const FString& Clue);
};