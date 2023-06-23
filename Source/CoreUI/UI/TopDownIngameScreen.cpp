//Fill copyright notice

#include"TopDownIngameScreen.h"

#include "Components/PanelWidget.h"
#include "CoreUI/Slate/CompoundWidgets/SBottomBuildingsPanel.h"

UTopDownIngameScreen::UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	//Height= FOptionalSize(400.0f);
	//Width = FOptionalSize(1000.0f);
}


void UTopDownIngameScreen::SynchronizeProperties()
{
	Super::SynchronizeProperties();
/*
	if(BottomPanelWidget.IsValid())
	{
		float SizeValue = 200.0f;
		TAttribute<FOptionalSize> SizeAttribute = TAttribute<FOptionalSize>::Create([SizeValue]() {
			return FOptionalSize(SizeValue);
		});

		BottomPanelWidget->SetSize_BoxHeight(SizeAttribute);
		BottomPanelWidget->SetSize_BoxWidth(SizeAttribute);

	}
	else
	{

		GEngine->AddOnScreenDebugMessage(-1, 5.0f,FColor::Black, " Widget creation failed ");
	}
*/

	if(BottomPanelWidget.IsValid())
	{
		BottomPanelWidget->SetSize_BoxHeight(Height);
		BottomPanelWidget->SetSize_BoxWidth(Width);
		BottomPanelWidget->SetBrush(BackgroundBrush);
	}
}

TSharedRef<SWidget> UTopDownIngameScreen::RebuildWidget()
{
	/*
	SAssignNew(BottomPanelWidget,SBottomBuildingsPanel)
	.BrushBG(BackgroundBrush)
	.SBHeight(Height)
	.SBWidth(Width);
	
	return BottomPanelWidget.ToSharedRef();*/
	SAssignNew(BottomPanelWidget,SBottomBuildingsPanel);
	
	return BottomPanelWidget.ToSharedRef();
}

void UTopDownIngameScreen::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	BottomPanelWidget.Reset();
}

TSharedPtr<FSlateBrush> UTopDownIngameScreen::Convert_UT2D_SlateBrush(UTexture2D* NewImage)
{
	FSlateBrush* Brush = new FSlateBrush();
	Brush->SetResourceObject(NewImage);
	TSharedPtr<FSlateBrush>  Image  =MakeShareable(Brush);
	return Image;
}


void UTopDownIngameScreen::SetBackgroundImage(UTexture2D* Texture)
{
	if(BackgroundBrush==nullptr)
	{
		FSlateBrush* Brush = new FSlateBrush();
		Brush->SetResourceObject(Texture);
		BackgroundBrush = MakeShareable(Brush);
	}
	else
	{
		BackgroundBrush->SetResourceObject(Texture);
	}
}

void UTopDownIngameScreen::SetSize(float inHeight, float inWidth)
{
	Height=inHeight;
	Width=inWidth;
}
