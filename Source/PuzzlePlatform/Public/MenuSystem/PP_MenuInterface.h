// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PP_MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPP_MenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PUZZLEPLATFORM_API IPP_MenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Host() {};

	virtual void Join(const FString& Address) {};
};
