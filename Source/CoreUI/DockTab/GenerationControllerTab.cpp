// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerationControllerTab.h"
#include "EditorStyleSet.h"
#include "Internationalization//Internationalization.h"
#include "WorkspaceMenuStructure/Public/WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructure/Public/WorkspaceMenuStructureModule.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Input/SSpinBox.h"


#define LOCTEXT_NAMESPACE "ControllerText"

FName SGenerationControllerTab::TabName(TEXT("ControllerTab"));
FOnGenerateButtonClick SGenerationControllerTab::GenerateDelegate;

SGenerationControllerTab::SGenerationControllerTab()
{

}

void SGenerationControllerTab::Construct(const FArguments& InArgs)
{

	GenerateDelegate.BindStatic(OnGenerateClick);
	
	ChildSlot
[
	SNew(SBox)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		
	SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.AutoHeight()
		[
			SNew(SExpandableArea)
			.HeaderContent()
			[    SNew(STextBlock)
				  .Text(FText::FromString("Generation"))
			]
			.BodyContent()
			[
				SNew(SButton)
				.Text(FText::FromString("ReGenerate"))
				.OnClicked(FOnClicked::CreateLambda([]() {
					GenerateDelegate.Execute();
					// Code to execute when the button is clicked
					return FReply::Handled();
					}))
			]
		]
		
	]

];
}

void SGenerationControllerTab::RegisterTabSpawner()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		TabName,
		FOnSpawnTab::CreateStatic(&SGenerationControllerTab::SpawnTab))
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"))
		.SetTooltipText(LOCTEXT("MyTabTooltip", "Open MyTab"))
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetDeveloperToolsMiscCategory())
		.SetDisplayName(LOCTEXT("Collapsible Box Tab", "CBOX"));

	
}

TSharedRef<SDockTab> SGenerationControllerTab::SpawnTab(const FSpawnTabArgs& SpawnTabArgs)
{
	// Create an instance of your widget
	TSharedPtr<SGenerationControllerTab> MyWidget = SNew(SGenerationControllerTab);

	// Add the widget to a SBox so we can control the size of the widget
	TSharedPtr<SBox> MyBox = SNew(SBox)
		.WidthOverride(100.0f)
		.HeightOverride(500.0f)
		[
			MyWidget.ToSharedRef()
		];

	// Set the content of the dockable tab to the SBox containing the widget
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		.Label(LOCTEXT("MyTabLabel", "My Tab"))
		[
			MyBox.ToSharedRef()
		];
}

FName SGenerationControllerTab::GetTabIdentifier() const
{
	return TabName;
}

bool SGenerationControllerTab::OnGenerateClick()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT(" Generating  "));
	}

	return true;
}


#undef  LOCTEXT_NAMESPACE
