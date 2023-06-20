#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Slate")
	FVector2D SizeBoxSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Slate")
	UTexture2D*BGImage;
	
	TSharedPtr<FSlateBrush>BackgroundBrush;
	

	TSharedPtr<FSlateBrush> Convert_UT2D_SlateBrush(UTexture2D* NewImage);


	void SetBackgroundImage (UTexture2D* Texture);
	void SetSize (FVector2D in_Size);

private:
	TSharedPtr<class SBottomBuildingsPanel> BottomPanelWidget;
	
};


