// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Barrel.h"




void UTank_Barrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Error, TEXT("reached elevate"));
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond);
		
		// move the barrel the right amount this frame
			//give a max elevation speed
}

