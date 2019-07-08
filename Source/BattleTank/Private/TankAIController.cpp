// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto AITank = GetAITank();
    if (!AITank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI is not working!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI is working %s!"), *(AITank->GetName()));
    }

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI player tank is not working!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI player tank is working %s!"), *(PlayerTank->GetName()));
    }
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

