// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_MainMenu.h"
#include "Components/Button.h"
#include "MenuSystem/PP_MenuInterface.h"

void UPP_MainMenu::SetMenuInterface(IPP_MenuInterface* Interface)
{
	MenuInterface = Interface;
}

bool UPP_MainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
	{
		return false;
	}

	// Setup
	if (!IsValid(HostButton) || !IsValid(JoinButton))
	{
		return false;
	}

	HostButton->OnPressed.AddDynamic(this, &UPP_MainMenu::HostServer);
	//JoinButton->OnPressed.AddDynamic(this, &UPP_MainMenu::JoinServer); // We comment this because we dont have the adress and the parameter is not valid to bind

	return true;
}

void UPP_MainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UPP_MainMenu::JoinServer(const FString& Address)
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Join(Address);
	}
}
