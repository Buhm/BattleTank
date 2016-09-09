// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Barrel.h"




void UTank_Barrel::Elevate(float RelativeSpeed)
{

	float ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	float ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationAngleDegrees, MaxElevationAngleDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));

	//UE_LOG(LogTemp, Warning, TEXT("%f: ClampedRelativeSpeed"), ClampedRelativeSpeed);

}


