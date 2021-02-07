// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_Menu.generated.h"

class IPP_MenuInterface;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_Menu : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	bool bShowMainMenuCursor = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	EMouseLockMode MouseLockMode = EMouseLockMode::DoNotLock;

	IPP_MenuInterface* MenuInterface;

public:

	void SetMenuInterface(IPP_MenuInterface* Interface);

	void Setup();

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	void Teardown();
	
};
