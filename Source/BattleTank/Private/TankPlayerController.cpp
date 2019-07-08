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
        // UE_LOG(LogTemp, Warning, TEXT("aim! %s"), *OutHitLocation.ToString());
    }

    // get world location if line trace through crosshair

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{
    // Find the crosshair position in coordinates 
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    UE_LOG(LogTemp, Warning, TEXT("screen location! %s"), *ScreenLocation.ToString());

    // Deproject the screen position of the crosshair to a world direction
    FVector CameraWorldLocation;
    FVector WorldDirection;
    if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
    {
        UE_LOG(LogTemp, Warning, TEXT("Look location! %s"), *WorldDirection.ToString());
    }
    // Line-Trace along that look direction and see what we hit.
    return true;
}