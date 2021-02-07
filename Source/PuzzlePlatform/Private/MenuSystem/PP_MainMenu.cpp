// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MenuSystem/PP_MenuInterface.h"
#include "Components/Widget.h"
#include "Components/EditableTextBox.h"

void UPP_MainMenu::SetMenuInterface(IPP_MenuInterface* Interface)
{
	MenuInterface = Interface;
}

void UPP_MainMenu::Setup()
{
	this->AddToViewport();

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

	// Setup the input data to interact with the menu
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget()); // The first widget to focus at start
	InputModeData.SetLockMouseToViewportBehavior(MouseLockMode); // The lock mouse behavior
	PC->SetInputMode(InputModeData); // Finally set it.

	// Show the cursor or not.
	PC->bShowMouseCursor = bShowMainMenuCursor;
}

void UPP_MainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	this->RemoveFromViewport();

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

	// Setup the input data to interact with the game (It's different !)
	FInputModeGameOnly InputModeData;
	PC->SetInputMode(InputModeData); // Finally set it.

	// Show the cursor or not.
	PC->bShowMouseCursor = false;

	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}

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
