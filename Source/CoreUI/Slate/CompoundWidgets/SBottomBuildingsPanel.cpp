// Fill out your copyright notice in the Description page of Project Settings.


#include "SBottomBuildingsPanel.h"

#include "SlateOptMacros.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SBottomBuildingsPanel::SBottomBuildingsPanel()
	:Size_BoxHeight(),
	Size_BoxWidth()
	{
	
	}

void SBottomBuildingsPanel::Construct(const FArguments& InArgs)
{
	SetSize_BoxHeight(InArgs._SBHeight);
	SetSize_BoxWidth(InArgs._SBWidth);
	SetBrush(BGBrush);
	
	
	ChildSlot
	[
		BuildUI()
	];
	
}

TSharedRef<SWidget> SBottomBuildingsPanel::BuildUI()
{

	TSharedPtr<SOverlay>RootOverlay;
	SAssignNew(RootOverlay,SOverlay)
	+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom) // Changed from VAlign_Center
		[
			SAssignNew(SizeBox,SBox)
			.WidthOverride_Lambda([this]() -> float {
			// Retrieve the current value of Size_BoxWidth attribute
			return Size_BoxWidth;
		})
		.HeightOverride_Lambda([this]() -> float {
			// Retrieve the current value of Size_BoxHeight attribute
			return Size_BoxHeight;
		})
				[
					SAssignNew(ImageWidget,SImage)
						.Image(BGBrush.Get())
				]
		];

	return RootOverlay.ToSharedRef();
}

void SBottomBuildingsPanel::SetSize_BoxHeight(float InHeight)
{
	Size_BoxHeight =InHeight;
}
/*
void SBottomBuildingsPanel::SetSize_BoxHeight(FOptionalSize InHeight)
{
	//Size_BoxHeight.Assign( *this ,InHeight);
	Size_BoxHeight.Set(*this ,InHeight.Get());
}

void SBottomBuildingsPanel::SetSize_BoxWidth(FOptionalSize InWidth)
{
	//Size_BoxWidth.Assign(*this ,InWidth);
	Size_BoxWidth.Set(*this,InWidth.Get());
}*/

void SBottomBuildingsPanel::SetSize_BoxWidth(float InWidth)
{
	Size_BoxWidth=InWidth;
}

void SBottomBuildingsPanel::SetBrush(TSharedPtr<FSlateBrush> Brush)
{
	if(BGBrush==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		BGBrush = MakeShareable(Br);
	}
	if(Brush==nullptr)
	{
		return;
	}
	BGBrush->SetResourceObject(Brush->GetResourceObject());

}

void SBottomBuildingsPanel::SetBrush(UTexture2D* Texture)
{
	if(BGBrush==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		BGBrush = MakeShareable(Br);
	}
	 if(Texture ==nullptr)
	 {
		 return;;
	 }
	BGBrush->SetResourceObject(Texture);
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
