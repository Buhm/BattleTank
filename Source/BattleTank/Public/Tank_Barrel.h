// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tank_Barrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTank_Barrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 = downward movement and +1 = upward movement
	void Elevate(float RelativeSpeed);
	

private:

	UPROPERTY(EditAnywhere, category = setup)
		float MaxDegreesPerSecond = 5;
	
	UPROPERTY(EditAnywhere, category = setup)
		float MaxElevationAngleDegrees = 40.0f;

	UPROPERTY(EditAnywhere, category = setup)
		float MinElevationAngleDegrees = 0.0f;

};
