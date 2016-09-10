// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank_Barrel.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	

}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
		TankAimingComponent->AimAt(HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetName(), *HitLocation.ToString())
} 


void ATank::setBarrelReference(UTank_Barrel* BarrelToSet)
{
	TankAimingComponent->setBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;

}


void ATank::setTurretReference(UTank_Turret* TurretToSet)
{
	TankAimingComponent->setTurretReference(TurretToSet);
}


void ATank::Fire()
{

	UE_LOG(LogTemp, Warning, TEXT("%s: Firing"), *GetName())

		if (!Barrel){ return; }

	FVector ProjectileSocketLocation = Barrel->GetSocketLocation(FName ("Projectile"));
	FRotator ProjectileLaunchDirection = Barrel->GetSocketRotation(FName("Projectile"));
	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileSocketLocation, ProjectileLaunchDirection);

}