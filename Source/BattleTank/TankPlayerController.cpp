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
		// get world location of linetrace through crosshair
		FVector HitLocation; //OUTPARAMETER
		GetSightRayHitLocation(HitLocation);
		
		if (GetSightRayHitLocation(HitLocation))	
		{
			GetControlledTank()->AimAt(HitLocation);
		}
		
	}

		
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

	
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{

	/// Ray-Cast/line-trace out to "reach" distance
	FHitResult HitResult;

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
			)
		{
			//draws the debug line
			DrawDebugLine(GetWorld(),
							StartLocation,
							EndLocation,
							FColor(255, 0, 0),
							false,
							0.0f,
							0,
							10.0f
						);

			HitLocation = HitResult.Location;
			AActor *ActorHit = HitResult.GetActor(); // see what we hit
				if (ActorHit)
				{
					//UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *ActorHit->GetName())
					return true;

				}
				else
				{
					HitLocation = FVector(0);
				}

		}
		
	return false;
}

