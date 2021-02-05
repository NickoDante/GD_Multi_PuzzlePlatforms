// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_MainMenu.generated.h"

class UButton;
class IPP_MenuInterface;

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
	UButton* JoinButton;

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
	void JoinServer(const FString& Address);
};
