// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widget.h"

#include "WebBrowserExt.generated.h"

/**
 * 
 */
UCLASS()
class MIVR_API UWebBrowserExt : public UWidget
{
	GENERATED_UCLASS_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUrlChanged, const FText&, Text);

	/**
	 * Load the specified URL
	 *
	 * @param NewURL New URL to load
	 */
	UFUNCTION(BlueprintCallable, Category="WebBrowserExt")
	void LoadURL(FString NewURL);

	/**
	 * Load a string as data to create a web page
	 *
	 * @param Contents String to load
	 * @param DummyURL Dummy URL for the page
	 */
	UFUNCTION(BlueprintCallable, Category="WebBrowserExt")
	void LoadString(FString Contents, FString DummyURL);

	/**
	* Executes a JavaScript string in the context of the web page
	*
	* @param ScriptText JavaScript string to execute
	*/
	UFUNCTION(BlueprintCallable, Category = "WebBrowserExt")
	void ExecuteJavascript(const FString& ScriptText);

	/**
	 * Get the current title of the web page
	 */
	UFUNCTION(BlueprintCallable, Category="WebBrowserExt")
	FText GetTitleText() const;

	/**
	* Gets the currently loaded URL.
	*
	* @return The URL, or empty string if no document is loaded.
	*/
	UFUNCTION(BlueprintCallable, Category = "WebBrowserExt")
	FString GetUrl() const;

	UFUNCTION(BlueprintCallable, Category = "WebBrowserExt")
	void BindUObject(const FString& Name, UObject* Object, bool bIsPermanent);

	UFUNCTION(BlueprintCallable, Category = "WebBrowserExt")
	void UnbindUObject(const FString& Name, UObject* Object, bool bIsPermanent);

	/** Called when the Url changes. */
	UPROPERTY(BlueprintAssignable, Category = "WebBrowserExt")
	FOnUrlChanged OnUrlChanged;

public:

	//~ Begin UWidget interface
	virtual void SynchronizeProperties() override;
	// End UWidget interface

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	/** URL that the browser will initially navigate to. The URL should include the protocol, eg http:// */
	UPROPERTY(EditAnywhere, Category=Appearance)
	FString InitialURL;

	/** Should the browser window show controls. */
	UPROPERTY(EditAnywhere, Category=Appearance)
	bool bShowControls;

	/** Should the browser window show the address bar. */
	UPROPERTY(EditAnywhere, Category=Appearance)
	bool bShowAddressBar;

	/** Should the browser window support transparency. */
	UPROPERTY(EditAnywhere, Category=Appearance)
	bool bSupportsTransparency;

	/** Opaque background color used before a document is loaded and when no document color is specified. */
	UPROPERTY(EditAnywhere, Category = Appearance)
	FColor backgroundColor;

	/** Desired size of the web browser viewport. */
	UPROPERTY(EditAnywhere, Category = Appearance)
	FVector2D viewportSize;

protected:
	TSharedPtr<class SWebBrowser> WebBrowserWidget;

protected:
	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface

	void HandleOnUrlChanged(const FText& Text);
};
