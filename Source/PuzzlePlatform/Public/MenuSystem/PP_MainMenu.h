// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_MainMenu.generated.h"

class UButton;
class IPP_MenuInterface;
class UWidgetSwitcher;
class UWidget;
class UEditableTextBox;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	bool bShowMainMenuCursor = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	EMouseLockMode MouseLockMode = EMouseLockMode::DoNotLock;

	// Use BindWidget to create a link from the Widget Button to this pointer to be managed on c++ (Has to be the SAME NAME)
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ShowJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPAdressField;

	IPP_MenuInterface* MenuInterface;

public:

	void SetMenuInterface(IPP_MenuInterface* Interface);

	void Setup();

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

protected:

	virtual bool Initialize() override;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void OpenSpecificMenu(UWidget* SpecificMenu);

	UFUNCTION()
	void JoinServer();
};
