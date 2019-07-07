// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player is not working!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player is working %s!"), *(ControlledTank->GetName()));
    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }

    FVector OutHitLocation; // OUT paramater

    if (GetSightRayHitLocation(OutHitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("Player is not working!"));
    }

    // get world location if line trace through crosshair

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{
    OutHitLocation = FVector(1.0);
    return true;
}