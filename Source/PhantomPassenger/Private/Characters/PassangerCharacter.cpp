#include "Characters/PassangerCharacter.h"
#include "Bus/BusManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
APassangerCharacter::APassangerCharacter()
{
    PrimaryActorTick.bCanEverTick = false;
    bIsPhantom = false;
    Archetype = EPassengerArchetype::Nervous;

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

// Called when the game starts or when spawned
void APassangerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APassangerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APassangerCharacter::RandomizePassenger(bool bAssignPhantom, int32 CurrentStop, const FString& Date, const FString& RouteNumber)
{
    bIsPhantom = bAssignPhantom;

    // Randomize archetype
    Archetype = static_cast<EPassengerArchetype>(FMath::RandRange(0, static_cast<int32>(EPassengerArchetype::Helper)));

    // Randomize ticket fields
    Ticket.Name = FString::Printf(TEXT("Passenger_%d"), FMath::RandRange(1000, 9999));
    Ticket.RouteNumber = RouteNumber;
    Ticket.Date = Date;
    Ticket.Time = FString::Printf(TEXT("%02d:%02d"), FMath::RandRange(6, 23), FMath::RandRange(0, 59));
    Ticket.SeatNumber = FString::FromInt(FMath::RandRange(1, 20));
}