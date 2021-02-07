// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_Menu.h"
#include "MenuSystem/PP_MenuInterface.h"

void UPP_Menu::SetMenuInterface(IPP_MenuInterface* Interface)
{
	MenuInterface = Interface;
}

void UPP_Menu::Setup()
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

void UPP_Menu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Teardown();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}

void UPP_Menu::Teardown()
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
}
