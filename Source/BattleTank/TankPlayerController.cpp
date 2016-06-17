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
		GetSightRayHitLocation(HitLocation);
		/*
		if (GetSightRayHitLocation(HitLocation))	
		{
			UE_LOG(LogTemp, Warning, TEXT("%s = hitlocation"), *HitLocation.ToString())	
		}
		*/
	}

		// get world location of linetrace through crosshair
		// if it hits the landscape
			// 
	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	//find the screen resolution
	GetViewportSize(ViewportSizeX, ViewportSizeY); // the sizes/arguments are OUT parameters



	//find the crosshair
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Crosshair location resolution: %s"), *ScreenLocation.ToString())
		//De-project the screen position of the crosshair to a world direction
		FVector LookDirection;
		GetLookDirection(ScreenLocation, LookDirection);
	
			// line-trace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);

		return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);

	//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString())
	
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)
{
	
	/// Ray-Cast/line-trace out to "reach" distance
	FHitResult HitResult;

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * Range);
	if (
		GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
		{
			HitLocation = HitResult.Location;
			UE_LOG(LogTemp, Warning, TEXT("test"))
			AActor *ActorHit = HitResult.GetActor(); // see what we hit
			if (ActorHit) 
				{
					UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *ActorHit->GetName())
				}
		
			//draws the debug line
			DrawDebugLine(
			GetWorld(),
			StartLocation,
			HitLocation,
			FColor(255, 0, 0),
			false,
			0.0f,
			0,
			10.0f
			);
		}

	return true;

}

FVector ATankPlayerController::GetReachLineStart()
{
	// get the player viewpoint this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT	PlayerViewPointRotation
	);

	return PlayerViewPointLocation;
}

