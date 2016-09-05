// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	

}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
	if (!barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = barrel->GetSocketLocation(FName("Projectile"));

	//calculate the outLaunchVelocity 


	if (UGameplayStatics::SuggestProjectileVelocity(

		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)

		) //calculate launch velocity
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		TankAimingComponent->AimAt(HitLocation, OutLaunchVelocity);
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *HitLocation.ToString())

	}


}


void ATank::setBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->setBarrelReference(BarrelToSet);
}

