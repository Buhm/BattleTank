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

	void Elevate(float RelativeSpeed);
	

private:

	UPROPERTY(EditAnywhere, category = setup)
		float MaxDegreesPerSecond = 20;
	
	UPROPERTY(EditAnywhere, category = setup)
		float MaxElevationAngleDegrees = 40;

	UPROPERTY(EditAnywhere, category = setup)
		float MinElevationAngleDegrees = 0;

};
