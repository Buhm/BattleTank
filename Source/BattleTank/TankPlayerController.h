// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	// reach of the view in order to grab
	float Reach = 2000.0f;

	ATank* GetControlledTank() const;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//start the tank moving the barrel so that a shot would hit where the crosshair intersects the world.
	void AimTowardsCrosshair();

	FVector GetReachLineStart();

	FVector GetReachLineEnd();
};
