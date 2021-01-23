// Fill out your copyright notice in the Description page of Project Settings.


#include "PP_PlatformTrigger.h"
#include "Components/BoxComponent.h"

// Sets default values
APP_PlatformTrigger::APP_PlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	SetRootComponent(TriggerVolume);
}

// Called when the game starts or when spawned
void APP_PlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(TriggerVolume))
	{
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APP_PlatformTrigger::OnOverlapBegin);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APP_PlatformTrigger::OnOverlapEnd);
	}
}

void APP_PlatformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Activated"));
}

void APP_PlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Deactivated"));
}

// Called every frame
void APP_PlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

