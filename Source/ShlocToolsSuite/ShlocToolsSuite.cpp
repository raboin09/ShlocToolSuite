// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ShlocToolsSuite.h"
#include "Modules/ModuleManager.h"
#include "Internationalization/StringTableRegistry.h"
#include "Kismet/KismetInternationalizationLibrary.h"

DEFINE_LOG_CATEGORY(LogShlocCore);

void FShlocToolsSuite::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();
	FStringTableRegistry::Get().UnregisterStringTable("MainMenu");
	LOCTABLE_FROMFILE_GAME("MainMenu", "UIStrings", "LocalizationText/en-us/LineCheckerText_EN.csv");
}

void FShlocToolsSuite::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();
}

IMPLEMENT_PRIMARY_GAME_MODULE(FShlocToolsSuite, ShlocToolsSuite, "UG_Alpha");