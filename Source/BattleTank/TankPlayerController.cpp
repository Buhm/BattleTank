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
	FHitResult HitLocation; //OUTPARAMETER
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	UE_LOG(LogTemp, Warning, TEXT("%s = hitlocation"), *HitLocation.ToString())

		GetWorld()->LineTraceSingleByObjectType(
			HitLocation,
			GetReachLineStart(),
			GetReachLineEnd(),
			FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
			TraceParameters
		);
		// get world location if linetrace through crosshair
		// if it hits the landscape
			// 
	return;
}

FVector ATankPlayerController::GetReachLineStart()
{
	// get the player viewpoint this tick
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		ViewPointLocation,	// OUT
		ViewPointRotation	// OUT
	);

	return ViewPointLocation;
}

FVector ATankPlayerController::GetReachLineEnd()
{
	// get the player viewpoint this tick
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		ViewPointLocation,   // OUT
		ViewPointRotation	// OUT
	);

	return ViewPointLocation + (ViewPointRotation.Vector() * Reach);
}