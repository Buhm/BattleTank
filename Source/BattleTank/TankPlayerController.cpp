// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h" //must be the last include


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrimaryActorTick.bCanEverTick = true;

	AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playcontroller not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has been possessed by TankPlayerController"), *ControlledTank->GetName())
			
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get Controlled Tank"))
		return;
	}
	else
	{
		FVector HitLocation; //OUTPARAMETER
			if (GetSightRayHitLocation(HitLocation))
			{
				UE_LOG(LogTemp, Warning, TEXT("%s = hitlocation"), *HitLocation.ToString())
			}

	}

		// get world location of linetrace through crosshair
		// if it hits the landscape
			// 
	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	HitLocation = FVector(1.0);
	return true;
}