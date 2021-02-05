// Fill out your copyright notice in the Description page of Project Settings.


#include "PP_GameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/PP_MainMenu.h"

UPP_GameInstance::UPP_GameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));

	///In the course, he load the menu here, but comments say it's not the best way to do it.
	///---------
// 	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
// 	if (!IsValid(MenuBPClass.Class))
// 	{
// 		return;
// 	}
// 
// 	MenuClass = MenuBPClass.Class;
	///---------
}

void UPP_GameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPP_GameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!IsValid(Engine))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		return;
	}

	// We put listen to this line, because we need to host a server listen other clients
	World->ServerTravel("/Game/Maps/PuzzlePlatformMap?listen");
}

void UPP_GameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!IsValid(Engine))
	{
		return;
	}

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Cyan, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PC = GetFirstLocalPlayerController();
	if (!IsValid(PC))
	{
		return;
	}

	PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UPP_GameInstance::LoadMenu()
{
	if (!IsValid(MenuClass))
	{
		return;
	}

	// Create the widget
	UPP_MainMenu* MenuWidget = CreateWidget<UPP_MainMenu>(this, MenuClass);

	if (!IsValid(MenuWidget))
	{
		return;
	}

	// Create the Widget setup.
	MenuWidget->Setup();

	// Set the interface of the game instance to the main menu
	MenuWidget->SetMenuInterface(this);
}

void UPP_GameInstance::PP_Host()
{
	Host();
}

void UPP_GameInstance::PP_Join(const FString& Address)
{
	Join(Address);
}

void UPP_GameInstance::PP_LoadMenu()
{
	LoadMenu();
}
