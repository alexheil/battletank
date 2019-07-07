// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	
	// start tank moving barrel so a shot will hit 
	// where crosshair intersects world.
	void AimTowardsCrosshair();

	// return an out paramter true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
