// Fill out your copyright notice in the Description page of Project Settings.


#include "SBottomBuildingsPanel.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBottomBuildingsPanel::Construct(const FArguments& InArgs)
{
	SizeboxSize  = InArgs._Size;
	BGBrush=InArgs._BGSlateBrush;
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
	.HeightOverride(SizeboxSize.X)
		[
			// Create the horizontal box
		SNew(SHorizontalBox)
			
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
			
				SNew(SImage)
				.Image(BGBrush.Get())
			]
		];

	return SizeBox;
}
FVector2D SBottomBuildingsPanel::CalcualteWidgetSize()
{
/*	// Get the screen or window dimensions
	FVector2D ScreenSize = FVector2D::ZeroVector;
	FWidgetPath WidgetPath;
	UGameViewportClient* GameViewportClient = GEngine->GameViewport;
	if (GameViewportClient)
	{
		TSharedRef<SWidget> ViewportWidgetRef = GameViewportClient->GetGameViewportWidget();
		if (FSlateApplication::Get().FindPathToWidget(ViewportWidgetRef, WidgetPath))
		{
			const FGeometry& ViewportGeometry = WidgetPath.GetLastGeometry();
			ScreenSize = ViewportGeometry.GetAbsoluteSize();
		}
	}
	*/

	//Viewport Size
	//FIntPoint GViewport = FIntPoint(GEngine->GameViewport->Viewport->GetSizeXY());
	//FVector2D MyVector(static_cast<FVector2D>(GViewport));
	//const FVector2D ViewportSize ((FVector2D)GViewport);

	////Viewport Center!
	//const FVector2D ViewportCenter = FVector2D(ViewportSize.X/2, ViewportSize.Y/2);
return FVector2D::ZeroVector;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
