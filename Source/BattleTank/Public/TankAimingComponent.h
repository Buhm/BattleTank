// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declarations
class BattleTank;
class UTank_Barrel; 
class UTank_Turret;

//Holds barrel's properties and elevate method.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void setBarrelReference(UTank_Barrel* BarrelToSet);

	void setTurretReference(UTank_Turret* TurretToSet);

	void AimAt(FVector HitLocation);

	UTank_Barrel* Barrel = nullptr;

	UTank_Turret* Turret = nullptr;

	UPROPERTY(EditAnywhere, category = firing)
		float LaunchSpeed = 4000.; // TODO continu to Find sensible default value later on


private:

	void MoveBarrelTowards(FVector AimDirection);

};

