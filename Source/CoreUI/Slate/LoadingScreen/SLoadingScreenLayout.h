// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COREUI_API SLoadingScreenLayout : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLoadingScreenLayout)
		{
		}

	SLATE_END_ARGS()

	SLoadingScreenLayout ();

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	/** Setter && Getters */ 

	//pure Data 
	void SetScreen_Height(float InHeight);
	void SetScreen_Width(float InWidth );

	//References
	TSharedPtr<SBox>  GetRootBox () {return RootBox;};
	TSharedPtr<SImage> GetBackgroundImage () {return Image_Background;};
	TSharedPtr<SImage> GetButtonImage () {return Image_StartButton;};

	//Background Brush
	void SetBrush_Background(TSharedPtr<FSlateBrush> Brush);
	void SetBrush_Background(UTexture2D* Texture);
	void SetBrush_Background(FLinearColor inColor);

	//Button Brush
	void SetBrush_StartButton(TSharedPtr<FSlateBrush> Brush);
	void SetBrush_StartButton(UTexture2D* Texture);
	void SetBrush_StartButton(FLinearColor inColor);
	
	



private:

	float Screen_Width ;
	float Screen_Height ;
	
	TSharedPtr<SBox> RootBox;
	
	TSharedPtr<SImage>Image_Background;
	TSharedPtr<FSlateBrush>Brush_Background;

	TSharedPtr<SImage>Image_StartButton;
	TSharedPtr<FSlateBrush>Brush_StartButton;
	TSharedPtr<FButtonStyle>Style_StartButton;

	
};
