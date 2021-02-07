// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_InGameMenu.h"
#include "MenuSystem/PP_MenuInterface.h"
#include "Components/Button.h"

bool UPP_InGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
	{
		return false;
	}

	// Setup
	if (IsValid(CancelButton))
	{
		CancelButton->OnPressed.AddDynamic(this, &UPP_InGameMenu::CancelMenu);
	}
	if (IsValid(QuitButton))
	{
		QuitButton->OnPressed.AddDynamic(this, &UPP_InGameMenu::QuitMatch);
	}

	return true;
}

void UPP_InGameMenu::CancelMenu()
{
	Teardown();
}

void UPP_InGameMenu::QuitMatch()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->Quit();
	}
}
