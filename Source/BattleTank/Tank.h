// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTank_Barrel;
class AProjectile; 
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, category = BarrelReference)
		void setBarrelReference(UTank_Barrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, category = TurretReference)
		void setTurretReference(UTank_Turret* TurretToSet);
	
	UFUNCTION(BlueprintCallable, category = firing)
		void Fire();


protected:

	UTankAimingComponent* TankAimingComponent = nullptr;


private:

	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	UPROPERTY(EditAnywhere, category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//local barrel refeerence for spawning projectiles
	UTank_Barrel* Barrel = nullptr;

};
