// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingCard.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBuildingCard::Construct(const FArguments& InArgs)
{
	Brush1=InArgs._inBrush1;
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
					.Image(Brush1.Get())
				]
         ]
         
	];
}

void SBuildingCard::SetBrush(TSharedPtr<FSlateBrush> Brush)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	if(Brush==nullptr)
	{
		return;
	}
	Brush1->SetResourceObject(Brush->GetResourceObject());
}

void SBuildingCard::SetBrush(UTexture2D* Texture)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	if(Texture ==nullptr)
	{
		return;;
	}
	Brush1->SetResourceObject(Texture);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
