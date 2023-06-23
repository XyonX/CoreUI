#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestUMG.generated.h"

/**
 * 
 */
UCLASS()
class COREUI_API UTestUMG : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UTestUMG(const FObjectInitializer& ObjectInitializer);
	
	//virtual void NativeConstruct() override;

	virtual void SynchronizeProperties() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;




	void SetBuildingImage (UTexture2D* Texture);



private:
	TSharedPtr<class SBuildingCard>BuildingCard;
	
	UTexture2D*BuildingImage;

	
};