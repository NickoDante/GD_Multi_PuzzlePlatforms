// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PP_MainMenu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPP_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Use BindWidget to create a link from the Widget Button to this pointer to be managed on c++
	UPROPERTY(meta = (BindWidget))
	UButton* Host;

	UPROPERTY(meta = (BindWidget))
	UButton* Join;
};
