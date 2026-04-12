// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPShooter_Gam415 : ModuleRules
{
	public FPShooter_Gam415(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara", "ProceduralMeshComponent" });
	}
}
