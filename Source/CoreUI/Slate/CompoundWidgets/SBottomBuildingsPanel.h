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
	: _Size(0,200)
	{}

	SLATE_ARGUMENT(FVector2D , Size)
	SLATE_ARGUMENT(UTexture2D*,BGImage)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedRef<SWidget> BuildUI();
	FVector2D CalcualteWidgetSize ();


	//Setters
	void SetImage( UTexture2D* NewImage);


	// helper function
	TSharedPtr<FSlateBrush> Convert_UT2D_SlateBrush (UTexture2D* NewImage);


private:
	//FString ButtonText;
	//FSlateBrush ButtonImage ;
	//TSharedPtr<FSlateBrush>  BGBrush ;
	//TSharedPtr<SVerticalBox>RootVertBox;
	//TSharedPtr<STextBlock> TextBlock;
	//TSharedPtr<SImage> ImageWidget;

	FVector2D SizeboxSize ;
	TSharedPtr<FSlateBrush> BGBrush ;
	TSharedPtr<SImage> ImageWidget;
};
