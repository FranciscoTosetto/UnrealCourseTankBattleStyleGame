// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"





void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerControlledTank = GetPlayerTank();

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not finding PlayerControlledTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found PlayerControlledTank: %s"), *(PlayerControlledTank->GetName()));
	}


	UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay"));
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	if (GetPlayerTank())
	{
		// TODO move towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if at the crosshair
	}
	Super::Tick(DeltaTime);
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


