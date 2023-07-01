// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CorePlugin/Spawnables/Spawnable.h"
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
	SLATE_ARGUMENT(UTexture2D* , inTexture)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	/** Setter and Getters */
	TSharedPtr<FSlateBrush> CreateBrush ();
	void SetBrush( TSharedPtr<FSlateBrush> Brush);
	void SetBrush( UTexture2D* Texture );
	void SetBrush( FLinearColor inColor );
	void SetBrush_New (UTexture2D* Texture);
	void SetSpawnable (USpawnable*inSpawnable){Spawnable=inSpawnable;};
	USpawnable*GetSpawnable(){return Spawnable;};


	/** Getter Function */
	

	/** Mouse Effects */
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	void UpdateCardSize ();

public:
	
	bool bIsDragging;
	FVector2D DragOffset;
	bool  bIsHovered;

private:

	TSharedPtr<FSlateBrush>Brush1;
	TSharedPtr<SBox>CardBox;
	TSharedPtr<SImage>Icon;
	USpawnable*Spawnable;
	
	
};
