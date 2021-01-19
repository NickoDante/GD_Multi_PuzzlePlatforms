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

void APP_MovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Get Start and En positions at global coordinates 
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void APP_MovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();
		bool bIsTravelCompleted = JourneyTravelled >= JourneyLength;

		if (bIsTravelCompleted)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Direction * (Speed * DeltaTime);
		SetActorLocation(Location);
	}

// 	if (!HasAuthority()) // Not on server = client.
// 	{
// 	}
}