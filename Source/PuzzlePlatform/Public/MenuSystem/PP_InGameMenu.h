// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/PP_Menu.h"
#include "PP_InGameMenu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_InGameMenu : public UPP_Menu
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

protected:

	virtual bool Initialize() override;

	UFUNCTION()
	void CancelMenu();

	UFUNCTION()
	void QuitMatch();
};
