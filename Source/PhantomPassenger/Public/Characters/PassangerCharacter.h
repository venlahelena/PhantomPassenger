#pragma once

#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "PassangerCharacter.generated.h"

UENUM(BlueprintType)    
enum class EPassengerArchetype : uint8
{
    Nervous,
    Chatty,
    Silent,
    Eccentric,
    Helper
};

USTRUCT(BlueprintType)
struct FPassengerTicket
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite) FString Name;
    UPROPERTY(BlueprintReadWrite) FString RouteNumber;
    UPROPERTY(BlueprintReadWrite) FString Date;
    UPROPERTY(BlueprintReadWrite) FString Time;
    UPROPERTY(BlueprintReadWrite) FString SeatNumber;
};

UCLASS()
class PHANTOMPASSENGER_API APassangerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APassangerCharacter();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPassengerArchetype Archetype;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPassengerTicket Ticket;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsPhantom;

    UFUNCTION(BlueprintCallable)
    void RandomizePassenger(bool bAssignPhantom, int32 CurrentStop, const FString& Date, const FString& RouteNumber);

protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;
};