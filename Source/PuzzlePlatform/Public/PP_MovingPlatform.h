// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PP_MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API APP_MovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public: 

	APP_MovingPlatform();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float Speed;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:

	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;

public: 

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
