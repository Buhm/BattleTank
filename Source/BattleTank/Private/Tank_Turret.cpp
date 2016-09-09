// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Turret.h"



void UTank_Turret::SideRotate(float DeltaRotator)  // feed it the (yaw) crosshair location
{
	float ClampedDeltaRotator = FMath::Clamp<float>(DeltaRotator, -1, +1);

	float RotationChange = ClampedDeltaRotator* 70.0f * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw + RotationChange;

	float Rotation = FMath::Clamp<float>(RawNewRotation, 0.0f, 0.0f);

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));

	UE_LOG(LogTemp, Warning, TEXT("%f: RawNewRotation"), RawNewRotation);

}
