// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreUI.h"

#include "Slate/CompoundWidgets/SBottomBuildingsPanel.h"

#define LOCTEXT_NAMESPACE "FCoreUIModule"

void FCoreUIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Register the tab spawner for the bottom buildings panel
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner("BottomBuildingsPanel", FOnSpawnTab::CreateRaw(this, &FCoreUIModule::SpawnBottomBuildingsPanel))
		.SetDisplayName(NSLOCTEXT("CoreUI", "BottomBuildingsPanel", "Bottom Buildings Panel"))
		.SetTooltipText(NSLOCTEXT("CoreUI", "BottomBuildingsPanelTooltipText", "Open the Bottom Buildings Panel tab."));
}

void FCoreUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// Unregister the tab spawner for the bottom buildings panel
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("BottomBuildingsPanel");
}
// This function creates an instance of the SBottomBuildingsPanel widget and returns it as a TSharedRef<SWidget>
TSharedRef<SDockTab> FCoreUIModule::SpawnBottomBuildingsPanel(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SBottomBuildingsPanel)
		];
}
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCoreUIModule, CoreUI)