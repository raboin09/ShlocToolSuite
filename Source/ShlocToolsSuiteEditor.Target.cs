// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShlocToolsSuiteEditorTarget : TargetRules
{
	public ShlocToolsSuiteEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V1;
		ExtraModuleNames.AddRange( new string[] { "ShlocToolsSuite" } );
	}
}
