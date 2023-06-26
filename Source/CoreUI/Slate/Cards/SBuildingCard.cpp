// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingCard.h"

#include "SlateOptMacros.h"
#include "CorePlugin/Helpers/DelegateHelper.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBuildingCard::Construct(const FArguments& InArgs)
{
	SetBrush(InArgs._inColor);
	ChildSlot
	[
         SNew(SOverlay)
         +SOverlay::Slot()
         .HAlign(HAlign_Center)
         .VAlign(VAlign_Center)
         [

	        
				SAssignNew(CardBox,SBox)
				.HeightOverride(60)
				.WidthOverride(60)
				[
			         SNew(SImage)
					  .Image(Brush1.Get())
				]
         ]
         
	];
}

void SBuildingCard::SetBrush(TSharedPtr<FSlateBrush> Brush)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	if(Brush==nullptr)
	{
		return;
	}
	Brush1->DrawAs =ESlateBrushDrawType::Image;
	Brush1->SetResourceObject(Brush->GetResourceObject());
}

void SBuildingCard::SetBrush(UTexture2D* Texture)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	if(Texture ==nullptr)
	{
		return;;
	}
	Brush1->SetResourceObject(Texture);
}

void SBuildingCard::SetBrush(FLinearColor inColor)
{
	if(Brush1==nullptr)
	{
		FSlateBrush* Br = new FSlateBrush();
		Brush1 = MakeShareable(Br);
	}
	Brush1->DrawAs=ESlateBrushDrawType::Box;
	Brush1->TintColor=inColor;
}

FReply SBuildingCard::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Card Dragged");
		// Set the drag offset to adjust the position of the widget during dragging
		DragOffset = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()) - MyGeometry.GetLocalSize() / 2.0f;
		bIsDragging = true;
		ADelegateHelper::DragDownDelegate.Broadcast();
		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SBuildingCard::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && bIsDragging)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Card Release");
		bIsDragging = false;
		// Perform any necessary actions upon dropping the card, such as spawning the building in the world

		ADelegateHelper::DragUpDelegate.Broadcast();
		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SBuildingCard::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	/*
	if (bIsDragging)
	{
		// Update the position of the card UI during the drag operation
		FVector2D MosueDelta =MouseEvent.GetScreenSpacePosition()-DragOffset;

		
		ADelegateHelper::OnDragDelegate.Broadcast();

		return FReply::Handled();
	}

	return FReply::Unhandled();*/

	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		// Get the mouse position relative to the widget's geometry
		FVector2D MousePosition = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		FVector2D ScreenPosition = MyGeometry.LocalToAbsolute(MousePosition);
		ADelegateHelper::OnDragDelegate.ExecuteIfBound(ScreenPosition);
        
		// Do something with the mouse position while the LMB is held down
        
		return FReply::Handled();
	}

	return FReply::Unhandled();
}


void SBuildingCard::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bIsHovered = true;
	UpdateCardSize();
	SCompoundWidget::OnMouseEnter(MyGeometry, MouseEvent);
}

void SBuildingCard::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	bIsHovered = false;
	UpdateCardSize();
	SCompoundWidget::OnMouseLeave(MouseEvent);
}

void SBuildingCard::UpdateCardSize()
{
	float TargetSize = bIsHovered? 60 :50 ;
	if(CardBox.IsValid())
	{
		CardBox->SetHeightOverride(TargetSize);
		CardBox->SetWidthOverride(TargetSize);
	}


}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
