// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COREUI_API SBottomBuildingsPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBottomBuildingsPanel)
	{}
	
	SLATE_ARGUMENT(TSharedPtr<FSlateBrush>,BrushBG)
	SLATE_ARGUMENT(float, SBHeight)
	SLATE_ARGUMENT(float, SBWidth)
	SLATE_END_ARGS()
	

	//FUNCTIONS
	
	SBottomBuildingsPanel();
	void Construct(const FArguments& InArgs);
	TSharedRef<SWidget> BuildUI();

	/** See WidthOverride attribute */
	void SetSize_BoxHeight(float InHeight);

	/** See HeightOverride attribute */
	void SetSize_BoxWidth(float InWidth );

	/**Set Brush */
	void SetBrush( TSharedPtr<FSlateBrush> Brush);

private:
	
	TSharedPtr<SBox> SizeBox;
	TSharedPtr<SOverlay> OverlayBox;
	TSharedPtr<SImage> ImageWidget;
	TSharedPtr<FSlateBrush> BGBrush ;
	
	
	float Size_BoxHeight;
	float Size_BoxWidth;
	
};
