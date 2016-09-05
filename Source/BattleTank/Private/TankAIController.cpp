// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetAIControlledTank();
	GetPlayerTank();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	PrimaryActorTick.bCanEverTick = true;
	if (GetPlayerTank)
	{
		FVector PlayerTankLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(PlayerTankLocation);
	}
	
	// fire if ready
}

ATank* ATankAIController::GetAIControlledTank() const
{
	ATank* AIControlledTank = GetControlledTank();

		if (!AIControlledTank)	{ return nullptr; }

	return AIControlledTank;
}



ATank * ATankAIController::GetPlayerTank() const
{
	auto FPController = GetWorld()->GetFirstPlayerController();
	auto ControlledTank = GetControlledTank();
	
		if (!FPController) {return nullptr;} //protects the pointer
		else
		{
			return Cast<ATank>(GetPawn());
		}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}


