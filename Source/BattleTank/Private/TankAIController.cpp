// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (GetPlayerTank())
    {
        // aim towards player
        FVector PlayerTankLocation = GetPlayerTank()->GetTargetLocation();
        GetAITank()->AimAt(PlayerTankLocation);
    }

}

ATank* ATankAIController::GetAITank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerTank) { return nullptr; }
    return Cast<ATank>(PlayerTank);
}

