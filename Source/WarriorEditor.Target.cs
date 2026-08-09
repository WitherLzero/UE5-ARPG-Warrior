// Paul Lyn All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class WarriorEditorTarget : TargetRules
{
	public WarriorEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;

		ExtraModuleNames.AddRange( new string[] { "Warrior" } );
	}
}
