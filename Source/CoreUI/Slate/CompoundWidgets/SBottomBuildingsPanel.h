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

	SLATE_ARGUMENT(FVector2D , Size)
	SLATE_ARGUMENT(TSharedPtr<FSlateBrush>,BrushBG)
	SLATE_END_ARGS()
	SBottomBuildingsPanel();

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedRef<SWidget> BuildUI();
	//FVector2D CalcualteWidgetSize ();


	//Setters
	void SetBrush( TSharedPtr<FSlateBrush> Brush);
	void SetSize( FVector2D in_size);


	// helper function
	//TSharedPtr<FSlateBrush> Convert_UT2D_SlateBrush (UTexture2D* NewImage);
	FVector2D SizeboxSize ;

private:
	//FString ButtonText;
	//FSlateBrush ButtonImage ;
	//TSharedPtr<FSlateBrush>  BGBrush ;
	//TSharedPtr<SVerticalBox>RootVertBox;
	//TSharedPtr<STextBlock> TextBlock;
	//TSharedPtr<SImage> ImageWidget;

	
	TSharedPtr<FSlateBrush> BGBrush ;
	TSharedPtr<SImage> ImageWidget;
};
