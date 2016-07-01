// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h" //must be the last include


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrimaryActorTick.bCanEverTick = true;

	//no need to protect pointers a added at construction

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
	
	if (!GetControlledTank()) {	return;	}
	else
	{
		// get world location of linetrace through crosshair
		FVector HitLocation; //OUTPARAMETER
		GetSightRayHitLocation(HitLocation);
		GetControlledTank()->OutputPlayerControllerAimInAimComponent(HitLocation);
	}

	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector HitLocation)
{
	//find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY); // the sizes/arguments are OUT parameters

	//find the crosshair
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

		//De-project the screen position of the crosshair to a world direction
		FVector LookDirection;
		if (GetLookDirection(ScreenLocation, LookDirection))
		{
			UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s , LookDirection: %s"), *ScreenLocation.ToString(), *LookDirection.ToString())
		}
		
	
		//UE_LOG(LogTemp, Warning, TEXT("Test"))
			// line-trace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);

		return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)
{
	FVector CameraWorldLocation; // To be discarded
	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, 
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{

	/// Ray-Cast/line-trace out to "reach" distance
	FHitResult HitResult; // OUT parameter used in linetracebychannel

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

		if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
			)
		{
			UE_LOG(LogTemp, Warning, TEXT("test"))
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
				UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *ActorHit->GetName())
				
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("test failed"))
			}
			
			return true;
		}
		
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
			HitLocation = FVector(0);
			
			return false;
		}
		
	
}

