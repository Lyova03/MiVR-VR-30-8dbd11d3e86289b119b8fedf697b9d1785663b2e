// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MiVR.h"

#include "SlateBasics.h"
#include "SlateCore.h"

#include "SWebBrowser.h"

#include "WebBrowserExt.h"

#define LOCTEXT_NAMESPACE "WebBrowserExt"

/////////////////////////////////////////////////////
// UWebBrowserExt

UWebBrowserExt::UWebBrowserExt(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsVariable = true;
}

void UWebBrowserExt::LoadURL(FString NewURL)
{
	if ( WebBrowserWidget.IsValid() )
	{
		return WebBrowserWidget->LoadURL(NewURL);
	}
}

void UWebBrowserExt::LoadString(FString Contents, FString DummyURL)
{
	if ( WebBrowserWidget.IsValid() )
	{
		return WebBrowserWidget->LoadString(Contents, DummyURL);
	}
}

void UWebBrowserExt::ExecuteJavascript(const FString& ScriptText)
{
	if (WebBrowserWidget.IsValid())
	{
		return WebBrowserWidget->ExecuteJavascript(ScriptText);
	}
}

FText UWebBrowserExt::GetTitleText() const
{
	if ( WebBrowserWidget.IsValid() )
	{
		return WebBrowserWidget->GetTitleText();
	}

	return FText::GetEmpty();
}

FString UWebBrowserExt::GetUrl() const
{
	if (WebBrowserWidget.IsValid())
	{
		return WebBrowserWidget->GetUrl();
	}

	return FString();
}

void UWebBrowserExt::BindUObject(const FString& Name, UObject* Object, bool bIsPermanent)
{
	if (WebBrowserWidget.IsValid())
	{
		WebBrowserWidget->BindUObject(Name, Object, bIsPermanent);
	}
}

void UWebBrowserExt::UnbindUObject(const FString& Name, UObject* Object, bool bIsPermanent)
{
	if (WebBrowserWidget.IsValid())
	{
		WebBrowserWidget->UnbindUObject(Name, Object, bIsPermanent);
	}
}

void UWebBrowserExt::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	WebBrowserWidget.Reset();
}

TSharedRef<SWidget> UWebBrowserExt::RebuildWidget()
{
	if ( IsDesignTime() )
	{
		return BuildDesignTimeWidget(SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("WebBrowserExt", "Web Browser Extention"))
			]);
	}
	else
	{
		WebBrowserWidget = SNew(SWebBrowser)
			.InitialURL(InitialURL)
			.ShowControls(bShowControls)
			.ShowAddressBar(bShowAddressBar)
			.SupportsTransparency(bSupportsTransparency)
			.BackgroundColor(backgroundColor)
			.ViewportSize(viewportSize)
			.OnUrlChanged(BIND_UOBJECT_DELEGATE(FOnTextChanged, HandleOnUrlChanged));

		return WebBrowserWidget.ToSharedRef();
	}
}

void UWebBrowserExt::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if ( WebBrowserWidget.IsValid() )
	{

	}
}

void UWebBrowserExt::HandleOnUrlChanged(const FText& InText)
{
	OnUrlChanged.Broadcast(InText);
}

#if WITH_EDITOR

const FText UWebBrowserExt::GetPaletteCategory()
{
	return LOCTEXT("Experimental", "Experimental");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
