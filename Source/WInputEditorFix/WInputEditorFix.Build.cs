// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WInputEditorFix : ModuleRules
{
	public WInputEditorFix(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"EnhancedInput", "InputEditor", "PropertyEditor",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"ApplicationCore",
				"BlueprintGraph",
				"Core",
				"CoreUObject",
				"DetailCustomizations",
				"Engine",
				"GraphEditor",
				"InputCore",
				"KismetCompiler",
				"SharedSettingsWidgets",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"AssetTools",
				"DeveloperSettings",
				"EditorSubsystem",
				"ToolMenus",
				"ContentBrowser",
				"SourceControl",
				"GameplayTags",
			}
		);
	}
}
