// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FixedCamera"));
	CameraComponent->SetupAttachment(RootComponent);

	CameraComponent->SetRelativeLocation(FVector(0.f, -400.f, 300.f));
	CameraComponent->SetRelativeRotation(FRotator(-20.f, 0.f, 0.f));
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
