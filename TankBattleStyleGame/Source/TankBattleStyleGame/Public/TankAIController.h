// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankPlayerController.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLESTYLEGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	void AimAt(FVector OutHitLocation);

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	ATank * GetControlledTank() const;

	ATank * GetPlayerTank() const;
};
