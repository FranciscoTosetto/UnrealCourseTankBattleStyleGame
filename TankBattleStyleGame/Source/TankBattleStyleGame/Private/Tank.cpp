// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankAimingComponent.h"



void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet)
	{
		return;
	}
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet)
	{
		return;
	}
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Fire Button"));
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	// no need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector OutHitLocation)
{
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Tank does not need a Tick

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

