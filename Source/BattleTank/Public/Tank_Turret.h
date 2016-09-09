// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tank_Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTank_Turret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 = downward movement and +1 = upward movement
	void SideRotate(float DeltaRotator);


private:

	UPROPERTY(EditAnywhere, category = setup)
		float MaxDegreesPerSecond = 5;

};