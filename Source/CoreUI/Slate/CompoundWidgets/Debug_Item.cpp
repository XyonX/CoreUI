// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug_Item.h"
#include  "Widgets/SWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Colors/SColorBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDebug_Item::Construct(const FArguments& InArgs)
{
	VariableName  = InArgs._VarName;
	VariableValue = InArgs._VarValue;
	NameFontInfo = InArgs._NameInfo;
	ValueFontInfo = InArgs._ValueInfo;
	NameBGColor	=InArgs._NameBGColor;
	ValueBGColor  = InArgs._ValueBGColor;
	RootHeight =InArgs._MaxHeight;
	RootWidth = InArgs._MaxWidth;
	NameBGBrush  = InArgs._NameBGBrush;
	ValueBGBrush  = InArgs._ValueBGBrush;
	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(RootWidth) 
		.HeightOverride(RootHeight)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBorder)
			.Padding(0.0f)
			.BorderBackgroundColor(FLinearColor::Blue)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[					
				SAssignNew(RootHorizontalBox,SHorizontalBox)
				.Tag(TEXT("RootBox"))
		
				+SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.MaxWidth(RootWidth/2)
					.Padding(10.0f)
					[
							SNew(SOverlay)
							+ SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SImage)
								.ColorAndOpacity(NameBGColor)
								.Image(NameBGBrush.Get())
							]
							+ SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SBorder)
								   .Padding(0.0f)
								   .BorderBackgroundColor(FLinearColor::Green)
								   .HAlign(HAlign_Center)
								   .VAlign(VAlign_Center)
								   [
										SNew(STextBlock)
										.Text(VariableName)
								   ]
							]
							
					]

				+SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.MaxWidth(RootWidth/2)
					.Padding(5.0f)
					[
						SNew(SOverlay)
							+ SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SImage)
								.ColorAndOpacity(ValueBGColor)
								.Image(ValueBGBrush.Get())
							]
							+ SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SBorder)
								   .Padding(0.0f)
								   .BorderBackgroundColor(FLinearColor::Green)
								   .HAlign(HAlign_Center)
								   .VAlign(VAlign_Center)
								   [
										SNew(STextBlock)
										.Text(VariableValue)
								   ]
							]
					]
			]

		]
	
	];
	
}

SDebug_Item::SDebug_Item()
{
	RootHeight=100;
	RootWidth  =10;

	NameBGColor  =FLinearColor(1.0,1.0,1.0,1.0);
	ValueBGColor  = FLinearColor (0.0,1.0,1.0,1.0);
}

SDebug_Item::SDebug_Item(int in_Width,  int in_Height ,FLinearColor NameColor ,FLinearColor ValueColor )
{
	RootHeight=in_Height;
	RootWidth  =in_Width;

	NameBGColor  =NameColor;
	ValueBGColor  = ValueColor;
	
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
