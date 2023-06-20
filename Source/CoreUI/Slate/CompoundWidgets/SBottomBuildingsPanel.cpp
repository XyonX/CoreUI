// Fill out your copyright notice in the Description page of Project Settings.


#include "SBottomBuildingsPanel.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SBottomBuildingsPanel::SBottomBuildingsPanel()
{
	SizeboxSize=FVector2D(500,500);
}

void SBottomBuildingsPanel::Construct(const FArguments& InArgs)
{

	SetSize(InArgs._Size);
	SetBrush(InArgs._BrushBG);
	ChildSlot
	[
		SNew(SBorder)
		.BorderBackgroundColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.5f))
		.Padding(0.0f)
		[
			BuildUI()
		]
	];
	
}

TSharedRef<SWidget> SBottomBuildingsPanel::BuildUI()
{

	// Create the size box
	TSharedRef<SBox> SizeBox = SNew(SBox)

	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Bottom)
	.HeightOverride(SizeboxSize.Y)
		[
			// Create the horizontal box
		SNew(SHorizontalBox)
			
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Fill)
			.AutoWidth()
			[
			
			SAssignNew(ImageWidget,SImage)
				.Image(BGBrush.Get())
			]
		];

	return SizeBox;
}
void SBottomBuildingsPanel::SetBrush(TSharedPtr<FSlateBrush> Brush)
{
	BGBrush=Brush;
	if(ImageWidget)
	ImageWidget->SetImage(BGBrush.Get());
}

void SBottomBuildingsPanel::SetSize(FVector2D in_size)
{
	SizeboxSize=in_size;
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
