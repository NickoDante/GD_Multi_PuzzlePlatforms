// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PP_PlatformTrigger.generated.h"

class UBoxComponent;
class APP_MovingPlatform;

UCLASS()
class PUZZLEPLATFORM_API APP_PlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	APP_PlatformTrigger();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerVolume;

private:

	UPROPERTY(EditAnywhere)
	TArray<APP_MovingPlatform*> PlatformsToTrigger;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
