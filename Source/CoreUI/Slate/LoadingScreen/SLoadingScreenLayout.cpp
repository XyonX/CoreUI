// Fill out your copyright notice in the Description page of Project Settings.


#include "SLoadingScreenLayout.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SLoadingScreenLayout::SLoadingScreenLayout()
	:
	Screen_Height(),
	Screen_Width()

{
	
}

void SLoadingScreenLayout::Construct(const FArguments& InArgs)
{

	ChildSlot
	[
		SAssignNew(RootBox, SBox)
		.WidthOverride_Lambda([this]() -> float {
			return Screen_Width;
		})
		.HeightOverride_Lambda([this]() -> float {
			return Screen_Height;
		})
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			  .HAlign(HAlign_Fill)
			  .VAlign(VAlign_Fill)
			  [
					SAssignNew(Image_Background,SImage)
					 .Image(Brush_Background.Get())
					
			  ]

			+SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Bottom)
				[
					  SNew(SOverlay)
					  +SOverlay::Slot()
					  .HAlign(HAlign_Fill)
					  .VAlign(VAlign_Fill)
					  [
							SAssignNew(Image_StartButton,SImage)
							 .Image(Brush_StartButton.Get())
					  ]
					  +SOverlay::Slot()
					  .HAlign(HAlign_Fill)
					  .VAlign(VAlign_Fill)
					  [
							SNew(SButton)
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							.ButtonStyle(Style_StartButton.Get())
					  ]
					
				]
		]
	];
	
}

void SLoadingScreenLayout::SetScreen_Height(float InHeight)
{
	Screen_Height=InHeight;
}

void SLoadingScreenLayout::SetScreen_Width(float InWidth)
{
	Screen_Width=InWidth;
}

void SLoadingScreenLayout::SetBrush_Background(TSharedPtr<FSlateBrush> Brush)
{
	if(Image_Background)
	Image_Background->SetImage(Brush.Get());
}

void SLoadingScreenLayout::SetBrush_Background(UTexture2D* Texture)
{
	if(Brush_Background==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush_Background = MakeShareable(Br);
	}
	if(Texture ==nullptr)
	{
		return;;
	}
	Brush_Background->DrawAs=ESlateBrushDrawType::Image;
	Brush_Background->SetResourceObject(Texture);
	Brush_Background->TintColor = FLinearColor::White;
}

void SLoadingScreenLayout::SetBrush_Background(FLinearColor inColor)
{
	if(Brush_Background==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush_Background = MakeShareable(Br);
	}
	Brush_Background->DrawAs=ESlateBrushDrawType::Box;
	Brush_Background->TintColor=inColor;

	
}

void SLoadingScreenLayout::SetBrush_StartButton(TSharedPtr<FSlateBrush> Brush)
{
	if(Image_StartButton)
		Image_StartButton->SetImage(Brush.Get());
}

void SLoadingScreenLayout::SetBrush_StartButton(UTexture2D* Texture)
{

	if(Brush_StartButton==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush_StartButton = MakeShareable(Br);
	}
	if(Texture ==nullptr)
	{
		return;;
	}
	Brush_StartButton->DrawAs=ESlateBrushDrawType::Image;
	Brush_StartButton->SetResourceObject(Texture);
	Brush_StartButton->TintColor = FLinearColor::White;
}

void SLoadingScreenLayout::SetBrush_StartButton(FLinearColor inColor)
{
	if(Brush_StartButton==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush_Background = MakeShareable(Br);
	}
	Brush_StartButton->DrawAs=ESlateBrushDrawType::Box;
	Brush_StartButton->TintColor=inColor;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
