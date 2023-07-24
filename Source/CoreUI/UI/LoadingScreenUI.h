#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadingScreenUI.generated.h"


UCLASS()
class COREUI_API ULoadingScreenUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** Overrides */
	
	virtual void NativeConstruct() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	// Getter

	TSharedPtr<class SLoadingScreenLayout> GetWidget (){return LoadingScreenWidget;};

	
	/* Data Variables */
	float ScreenWidth;
	float ScreenHeight;

	TSharedPtr<FSlateBrush> Brush_Background;
	TSharedPtr<FSlateBrush> Brush_StartButton;


private:


	/** Reference */
	
	TSharedPtr<class SLoadingScreenLayout> LoadingScreenWidget;
	
	
};
