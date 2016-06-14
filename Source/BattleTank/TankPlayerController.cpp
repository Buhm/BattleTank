// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h" //must be the last include

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


