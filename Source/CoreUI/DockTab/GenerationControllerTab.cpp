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
			SAssignNew(MainHorizontalBox,SHorizontalBox)
		]
	];

	MainHorizontalBox->AddSlot()
	.VAlign(VAlign_Fill)
	.HAlign(HAlign_Left)
	.FillWidth(0.7f)
	[
		SAssignNew(Widget, SVerticalBox)
	];
	SB_TabSwitcher = MakeShareable(new FSlateBrush);
	
	SB_TabSwitcher->TintColor == FLinearColor(1.0f, 0.0f, 1.0f, 1.0f); // red color
	SB_TabSwitcher->DrawAs = ESlateBrushDrawType::Box;
	SB_TabSwitcher->Margin = FMargin(0.0f, 0.0f, 0.0f, 0.0f);

	
	MainHorizontalBox->AddSlot()
	.VAlign(VAlign_Fill)
	.HAlign(HAlign_Right)
	.FillWidth(0.3f)
	[
	  SNew(SBorder)
	  .BorderBackgroundColor( FLinearColor(1.0f,0.0f,0.0f,1.0f))
	  [
		SAssignNew(TabSwitcher,SVerticalBox)
		+ SVerticalBox::Slot() // Add a slot for the SImage widget
		[
			SNew(SImage)
			.Image(SB_TabSwitcher.Get())
			.ColorAndOpacity(FLinearColor(1.0,1.0f,1.0f,0.5f))
		]
		
	  ]
	];

	
	Widget->AddSlot()
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Top)
	[
			
		SNew(SExpandableArea)
		.BorderBackgroundColor(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f))
		.BodyBorderBackgroundColor(FLinearColor(0.25f, 0.25f, 0.25f, 0.5f))
		.HeaderContent()
		[
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
					[
					  SNew(STextBlock)
					  .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 10))
					  .ColorAndOpacity(FLinearColor::White)
					  .Text(FText::FromString("Generation"))

					]
		]
		.BodyContent()
		[
			SNew(SButton)
			.Text(FText::FromString("ReGenerate"))
			.ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
			.OnClicked(FOnClicked::CreateLambda([]() {
				GenerateDelegate.Execute();
				return FReply::Handled();
			}))
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
	//if (GEngine) {
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT(" Generating  "));
	//}

	return true;
}


#undef  LOCTEXT_NAMESPACE
