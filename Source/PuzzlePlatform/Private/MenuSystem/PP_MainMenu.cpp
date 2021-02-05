// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/PP_MainMenu.h"
#include "Components/Button.h"

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
	JoinButton->OnPressed.AddDynamic(this, &UPP_MainMenu::JoinServer);

	return true;
}

void UPP_MainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server!"));
}

void UPP_MainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna join a server!"));
}
