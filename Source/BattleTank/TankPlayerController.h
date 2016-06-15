// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define Int32 = int;
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
	
public:

	virtual void BeginPlay() override;

	int32 ViewportSizeX, ViewportSizeY;

	ATank* GetControlledTank() const;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//start the tank moving the barrel so that a shot would hit where the crosshair intersects the world.
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);
};
