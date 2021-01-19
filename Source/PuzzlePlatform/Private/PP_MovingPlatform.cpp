// Fill out your copyright notice in the Description page of Project Settings.


#include "PP_MovingPlatform.h"

APP_MovingPlatform::APP_MovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	Speed = 10.0f;

	// The new way
	bReplicates = true;
	SetReplicatingMovement(true);
}

void APP_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Direction * (Speed * DeltaTime);
		SetActorLocation(Location);
	}

// 	if (!HasAuthority()) // Not on server = client.
// 	{
// 	}
}