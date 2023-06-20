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
	UTopDownIngameScreen(const FObjectInitializer& ObjectInitializer ,UTexture2D* Image ,FVector2D Size );
	
	//virtual void NativeConstruct() override;

	virtual void SynchronizeProperties() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Slate")
	FVector2D SizeBoxSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Slate")
	UTexture2D*BGImage;

private:
	TSharedPtr<class SBottomBuildingsPanel> BottomPanelWidget;
	
};
