// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingCard.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBuildingCard::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
         SNew(SOverlay)
         +SOverlay::Slot()
         .HAlign(HAlign_Center)
         .VAlign(VAlign_Center)
         [
				SNew(SBox)
				.HeightOverride(200)
				.WidthOverride(200)
				[
					SNew(SImage)
					.Image(InArgs._inBrush1.Get())
				]
         ]
         
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
