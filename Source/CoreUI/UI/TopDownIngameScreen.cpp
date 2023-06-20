//Fill copyright notice

#include"TopDownIngameScreen.h"

#include "Components/PanelWidget.h"
#include "CoreUI/Slate/CompoundWidgets/SBottomBuildingsPanel.h"

UTopDownIngameScreen::UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}


void UTopDownIngameScreen::SynchronizeProperties()
{
	Super::SynchronizeProperties();


	if(BottomPanelWidget.IsValid())
	{
		BottomPanelWidget->SetBrush(BackgroundBrush);
		BottomPanelWidget->SetSize(SizeBoxSize);
	}
	// Display the SizeBoxSize as an on-screen debug message
	//FString SizeBoxSizeString = SizeBoxSize.ToString();
	if(BottomPanelWidget)
	{
			FString SizeBoxSizeString = BottomPanelWidget->SizeboxSize.ToString();
        	FColor MessageColor = FColor::Yellow;
        	float DisplayTime = 2.0f;
        	int32 Key = -1; // Automatically assigned key
        	GEngine->AddOnScreenDebugMessage(Key, DisplayTime, MessageColor, SizeBoxSizeString);
	}
	FString SizeBoxSizeString ="WIDGET CREATION FAILED";
	FColor MessageColor = FColor::Yellow;
	float DisplayTime = 2.0f;
	int32 Key = -1; // Automatically assigned key
	GEngine->AddOnScreenDebugMessage(Key, DisplayTime, MessageColor, SizeBoxSizeString);
	
}

TSharedRef<SWidget> UTopDownIngameScreen::RebuildWidget()
{
	Super::RebuildWidget();
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

void UTopDownIngameScreen::SetSize(FVector2D in_Size)
{
	SizeBoxSize=in_Size;
}