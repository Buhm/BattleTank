// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_Barrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}

void UTankAimingComponent::setBarrelReference(UTank_Barrel* BarrelToSet)
{

	Barrel = BarrelToSet;

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
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();

			MoveBarrelTowards(AimDirection);
	}

	 //calculated launch velocity and provided the output, protected the pointer
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation and aimdirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	float DegreesPerSecond = 5;
	Barrel->Elevate(DegreesPerSecond);

}
