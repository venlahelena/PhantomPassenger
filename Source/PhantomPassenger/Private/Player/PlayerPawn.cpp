// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FixedCamera"));
	CameraComponent->SetupAttachment(RootComponent);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// The camera's fixed position and rotation are a core element of the game's design,
	// providing the intended player perspective and gameplay experience.
	// We set the camera's world location and rotation here (not in the constructor)
	// because Unreal Engine finalizes actor transforms after spawning. Setting world transforms
	// in the constructor may be overridden or ignored. By configuring the camera in BeginPlay,
	// we guarantee it is placed exactly as required for the game's visual and interactive style.
	if (CameraComponent)
	{
		CameraComponent->SetWorldLocation(FVector(141868.850202f, 16228.001705f, 111734.111074f));
		CameraComponent->SetWorldRotation(FRotator(-29.2f, 128.60183f, 0.0f));
	}
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
