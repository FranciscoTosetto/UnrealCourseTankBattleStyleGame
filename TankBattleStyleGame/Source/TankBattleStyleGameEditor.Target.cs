// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TankBattleStyleGameEditorTarget : TargetRules
{
	public TankBattleStyleGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "TankBattleStyleGame" } );
	}
}
