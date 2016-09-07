// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTank_Barrel; 

//Holds barrel's properties and elevate method.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void setBarrelReference(UTank_Barrel* BarrelToSet);

	//TODO add SetTurretReference

	void AimAt(FVector HitLocation);

	UPROPERTY(EditAnywhere, category = firing)
		float LaunchSpeed = 100000.; // TODO Find sensible default value later on

	UTank_Barrel* Barrel = nullptr;

private:

	void MoveBarrelTowards(FVector AimDirection);
};

