// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tank_Barrel.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTank_Barrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float DegreesPerSecond);
	

private:

	
};
