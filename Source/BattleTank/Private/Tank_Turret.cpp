// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Turret.h"



void UTank_Turret::SideRotate(float DeltaRotator)  // feed it the (yaw) crosshair location
{
	float ClampedDeltaRotator = FMath::Clamp<float>(DeltaRotator, -1, +1);

	float RotationChange = ClampedDeltaRotator* MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

	//UE_LOG(LogTemp, Warning, TEXT("%f: RawNewRotation"), RawNewRotation);

}
