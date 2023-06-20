//Fill copyright notice

#include"TopDownIngameScreen.h"

#include "Components/PanelWidget.h"
#include "CoreUI/Slate/CompoundWidgets/SBottomBuildingsPanel.h"

UTopDownIngameScreen::UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

UTopDownIngameScreen::UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer, UTexture2D* Image,
	FVector2D Size)
: Super(ObjectInitializer)
{
	BGImage=Image;
	SizeBoxSize=Size;
}

void UTopDownIngameScreen::SynchronizeProperties()
{
	Super::SynchronizeProperties();


	if(BottomPanelWidget.IsValid())
	{
		BottomPanelWidget->SetImage(BGImage);
	}
}

TSharedRef<SWidget> UTopDownIngameScreen::RebuildWidget()
{
	Super::RebuildWidget();
	// Create an instance of the SBottomBuildingsPanel widget
	TSharedRef<SBottomBuildingsPanel> BottomBuildingsPanel = SNew(SBottomBuildingsPanel)
	.Size(SizeBoxSize)
	.BGImage(BGImage);

	return BottomBuildingsPanel;

}

void UTopDownIngameScreen::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	BottomPanelWidget.Reset();
}
