// Fill out your copyright notice in the Description page of Project Settings.

#include "MiVR.h"

#include "WebBrowserListener.h"

bool UWebBrowserListener::DUMMY(FString& Name)
{
	Name = FPaths::ConvertRelativePathToFull(FPaths::GameDir() + TEXT("WebBrowserTest/test.html"));

	return false;
}
