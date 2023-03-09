// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug_Item.h"
#include  "Widgets/SWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDebug_Item::Construct(const FArguments& InArgs)
{
	VariableName  = InArgs._VarName;
	VariableValue = InArgs._VarValue;
	TSharedPtr<SHorizontalBox>DWD;
	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(10)
		.HeightOverride(50)
		.Padding(1)
		
		[
			SAssignNew(RootHorizontalBox,SHorizontalBox)
				.Tag(TEXT("RootBox"))
		
			+SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				.Padding(5.0f)
				[
					SNew(SOverlay)
						+ SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
							[
								SNew(SImage)
								.ColorAndOpacity(FLinearColor(1, 1, 1, 1))     
								//.Image(backgroundImage)
							]
						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(VariableName)
							]
				]

			+SHorizontalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.AutoWidth()
				.Padding(5.0f)
				[
					SNew(STextBlock)
					.Text(VariableValue)
				]

			]
	];
	
}

void SDebug_Item::SetName(FText in_Name)
{
	VariableName = in_Name;
}

void SDebug_Item::SetValue(FText in_Value)
{
	VariableValue = in_Value;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
