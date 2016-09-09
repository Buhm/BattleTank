// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Barrel.h"
#include "Tank_Turret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; //TODO should this really tick?
	
	// ...
}

void UTankAimingComponent::setBarrelReference(UTank_Barrel* BarrelToSet)
{

	Barrel = BarrelToSet;

}

void UTankAimingComponent::setTurretReference(UTank_Turret* TurretToSet)
{

	Turret = TurretToSet;

}


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//calculate the outLaunchVelocity 

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{

		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found"), Time);

		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);

	}
	else
	{

		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: NO Aim Solution Found"), Time);

	}
	 //calculated launch velocity and provided the output, protected the pointer
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation and aimdirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

		Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation and aimdirection
	auto TurretRotator = Turret->GetRightVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;
	// find the yaw for the crosshair to stop the tank turning when crosshair yaw location is reached

		Turret->SideRotate(DeltaRotator.Yaw);

}