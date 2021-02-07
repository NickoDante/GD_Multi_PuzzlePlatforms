// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/PP_MenuInterface.h"
#include "PP_GameInstance.generated.h"

class UUserWidget;

/**
 * Its alive always in the game. It works to join a server or not. It can be tested through console commands
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_GameInstance : public UGameInstance, public IPP_MenuInterface
{
	GENERATED_BODY()

public: 

	UPP_GameInstance(const FObjectInitializer & ObjectInitializer);

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	TSubclassOf<UUserWidget> MenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	TSubclassOf<UUserWidget> InGameMenuClass;

public:

	virtual void Init() override;

	virtual void Host() override;

	virtual void Join(const FString& Address) override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(BlueprintCallable)
	void LoadSpecificMenu(TSubclassOf<UUserWidget> SpecificMenu);

public:

	UFUNCTION(exec)
	void PP_Host();

	UFUNCTION(exec)
	void PP_Join(const FString& Address);

	UFUNCTION(exec)
	void PP_LoadMenu();
};
