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
	
private:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 100000;

	int32 ViewportSizeX, ViewportSizeY;

	ATank* GetControlledTank() const;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//start the tank moving the barrel so that a shot would hit where the crosshair intersects the world.
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);

	bool GetLookDirection(FVector2D ScreenLocation, FVector WorldDirection) const; 

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
