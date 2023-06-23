#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "TopDownIngameScreen.generated.h"

/**
 * 
 */
UCLASS()
class COREUI_API UTopDownIngameScreen : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer);
	
	//virtual void NativeConstruct() override;

	virtual void SynchronizeProperties() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;


	//Functions
	TSharedPtr<FSlateBrush> Convert_UT2D_SlateBrush(UTexture2D* NewImage);

	void SetBackgroundImage (UTexture2D* Texture);
	void SetSize (float inHeight , float inWidth );


private:
	TSharedPtr<class SBottomBuildingsPanel> BottomPanelWidget;

	
	FVector2D SizeBoxSize;
	UTexture2D*BGImage;
	TSharedPtr<FSlateBrush>BackgroundBrush;
	
	float Width;
	float Height;
	
};


