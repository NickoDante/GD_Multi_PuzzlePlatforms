// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MenuSystem/PP_MenuInterface.h"
#include "Components/Widget.h"
#include "Components/EditableTextBox.h"

bool UPP_MainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
	{
		return false;
	}

	// Setup
	if (IsValid(HostButton))
	{
		HostButton->OnPressed.AddDynamic(this, &UPP_MainMenu::HostServer);
	}
	if (IsValid(ShowJoinMenuButton))
	{
		ShowJoinMenuButton->OnPressed.AddDynamic(this, &UPP_MainMenu::OpenJoinMenu);
	}
	if (IsValid(BackButton))
	{
		BackButton->OnPressed.AddDynamic(this, &UPP_MainMenu::OpenMainMenu);
	}
	if (IsValid(JoinButton))
	{
		JoinButton->OnPressed.AddDynamic(this, &UPP_MainMenu::JoinServer);
	}
	if (IsValid(QuitButton))
	{
		QuitButton->OnPressed.AddDynamic(this, &UPP_MainMenu::QuitGame);
	}

	return true;
}

void UPP_MainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UPP_MainMenu::OpenJoinMenu()
{
	OpenSpecificMenu(JoinMenu);
}

void UPP_MainMenu::OpenMainMenu()
{
	OpenSpecificMenu(MainMenu);
}

void UPP_MainMenu::OpenSpecificMenu(UWidget* SpecificMenu)
{
	if (!IsValid(MenuSwitcher))
	{
		return;
	}

	if (!IsValid(SpecificMenu))
	{
		return;
	}

	MenuSwitcher->SetActiveWidget(SpecificMenu);
}

void UPP_MainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		FText IPAdressText = FText();

		if (IsValid(IPAdressField))
		{
			IPAdressText = IPAdressField->GetText();
		}

		const FString IPAdress = IPAdressText.ToString();
		MenuInterface->Join(IPAdress);
	}
}

void UPP_MainMenu::QuitGame()
{
	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		return;
	}

	// We need the Player Controller to set the input mode for this menu
	APlayerController* PC = World->GetFirstPlayerController();
	if (!IsValid(PC))
	{
		return;
	}

	PC->ConsoleCommand("Quit");
}
