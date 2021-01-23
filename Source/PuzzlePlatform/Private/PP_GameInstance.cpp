// Fill out your copyright notice in the Description page of Project Settings.


#include "PP_GameInstance.h"
#include "Engine/Engine.h"

UPP_GameInstance::UPP_GameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPP_GameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPP_GameInstance::PP_Host()
{
	UEngine* Engine = GetEngine();
	if (!IsValid(Engine))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));
}

void UPP_GameInstance::PP_Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!IsValid(Engine))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Cyan, FString::Printf(TEXT("Joining %s"), *Address));
}
