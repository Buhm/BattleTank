// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "BattleTank.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties

	ATank();

	UFUNCTION(BluePrintCallable, Category = Setup)
	void setBarrelReference(UStaticMeshComponent* BarrelToSet);

	UPROPERTY(EditAnywhere, category = firing)
	float LaunchSpeed = 10000.; // TODO Find sensible default value later on
	
	void AimAt(FVector HitLocation);

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;


private:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	
};
