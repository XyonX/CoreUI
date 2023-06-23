// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COREUI_API SBuildingCard : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBuildingCard)
		{
		}
	SLATE_ARGUMENT(FLinearColor , inColor)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	void SetBrush( TSharedPtr<FSlateBrush> Brush);
	void SetBrush( UTexture2D* Texture );
	void SetBrush( FLinearColor inColor );
public:

	TSharedPtr<FSlateBrush>Brush1; 
};
