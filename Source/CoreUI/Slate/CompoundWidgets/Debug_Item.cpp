// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug_Item.h"
#include  "Widgets/SWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDebug_Item::Construct(const FArguments& InArgs)
{
	VariableName  = InArgs._VarName;
	VariableValue = InArgs._VarValue;
	NameFontInfo = InArgs._NameInfo;
	ValueFontInfo = InArgs._ValueInfo;
	TSharedPtr<SHorizontalBox>DWD;
	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(RootWidth)
		.HeightOverride(RootWidth)
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
								.ColorAndOpacity(NameBGColor)     
								//.Image(backgroundImage)
							]
						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(VariableName)
								.Font(NameFontInfo)
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
					.Font(ValueFontInfo)
				]
		]		
	];
	
}

SDebug_Item::SDebug_Item(int in_Width,  int in_Height )
{
	RootHeight=in_Height;
	RootWidth  =in_Width;

	NameBGColor  =FLinearColor(1.0,1.0,1.0,1.0);
	ValueBGColor  = FLinearColor (0.0,1.0,1.0,1.0);
	
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
