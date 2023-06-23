// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingCard.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBuildingCard::Construct(const FArguments& InArgs)
{
	SetBrush(InArgs._inColor);
	ChildSlot
	[
         SNew(SOverlay)
         +SOverlay::Slot()
         .HAlign(HAlign_Center)
         .VAlign(VAlign_Center)
         [
				SNew(SBox)
				.HeightOverride(50)
				.WidthOverride(50)
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
	Brush1->DrawAs =ESlateBrushDrawType::Image;
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

void SBuildingCard::SetBrush(FLinearColor inColor)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	Brush1->DrawAs=ESlateBrushDrawType::Box;
	Brush1->TintColor=inColor;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
