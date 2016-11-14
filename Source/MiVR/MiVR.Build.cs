// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MiVR : ModuleRules
{
	public MiVR(TargetInfo Target)
	{
        //PublicIncludePaths.Add("Runtime/WebBrowser/Public");
        //PrivateIncludePaths.Add("Runtime/WebBrowser/Private");

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "WebBrowser",
            "UMG"
        });

		//PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "WebBrowser" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
