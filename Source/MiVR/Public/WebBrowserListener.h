// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "WebBrowserExt.h"
#include "WebBrowserListener.generated.h"

/**
 * 
 */
UCLASS()
class MIVR_API UWebBrowserListener : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "WebBrowserListener")
	bool DUMMY(FString& Name);

	UFUNCTION(BlueprintImplementableEvent, Category = "WebBrowserListener")
	void OnWebButtonPressed(const FString& Name);

	UFUNCTION(BlueprintImplementableEvent, Category = "WebBrowserListener")
	void OnSomeButtonPressed(const FString& Name);
};
