// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetAIControlledTank();
	GetPlayerTank();
	UE_LOG(LogTemp, Warning, TEXT("%s has found FPController: %s"), *GetAIControlledTank()->GetName(), *GetPlayerTank()->GetName())
}



ATank* ATankAIController::GetAIControlledTank() const
{
	auto AIControlledTank = GetControlledTank();
	
		if (!AIControlledTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s not possessing a AI Controller"), *AIControlledTank->GetName());
			return nullptr;
		}
		
	//UE_LOG(LogTemp, Warning, TEXT("%s has been possessed by AI Controller"), *AIControlledTank->GetName())
	return AIControlledTank;
		
		
}



ATank * ATankAIController::GetPlayerTank() const
{
	auto FPController = GetWorld()->GetFirstPlayerController();
	auto ControlledTank = GetControlledTank();
	

		if (!FPController) {return nullptr;} //protects the pointer
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("%s has found FPController!"), *ControlledTank->GetName())
		}

	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

