// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PP_GameInstance.generated.h"

/**
 * Its alive always in the game. It works to join a server or not. It can be tested through console commands
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public: 

	UPP_GameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init() override;
};
