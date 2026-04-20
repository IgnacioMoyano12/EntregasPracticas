// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EntregasPracticas1 : ModuleRules
{
	public EntregasPracticas1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EntregasPracticas1",
			"EntregasPracticas1/Variant_Platforming",
			"EntregasPracticas1/Variant_Platforming/Animation",
			"EntregasPracticas1/Variant_Combat",
			"EntregasPracticas1/Variant_Combat/AI",
			"EntregasPracticas1/Variant_Combat/Animation",
			"EntregasPracticas1/Variant_Combat/Gameplay",
			"EntregasPracticas1/Variant_Combat/Interfaces",
			"EntregasPracticas1/Variant_Combat/UI",
			"EntregasPracticas1/Variant_SideScrolling",
			"EntregasPracticas1/Variant_SideScrolling/AI",
			"EntregasPracticas1/Variant_SideScrolling/Gameplay",
			"EntregasPracticas1/Variant_SideScrolling/Interfaces",
			"EntregasPracticas1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
