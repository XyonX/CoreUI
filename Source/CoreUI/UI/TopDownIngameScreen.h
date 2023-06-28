#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CorePlugin/Spawnables/Spawnable.h"
#include "TopDownIngameScreen.generated.h"


UCLASS()
class COREUI_API UTopDownIngameScreen : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** Overrides */
	
	virtual void NativeConstruct() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;


	/** Setter And Getter */

	/*Data */
	void SetSize (float inHeight , float inWidth ){Width=inWidth;Height=inHeight;};
	void SetSpawnable (TMap<int32, USpawnable*>* inSpawnables){Spawnables=inSpawnables;};


	/*References */
	TSharedPtr<class SBottomBuildingsPanel> GetWidget () {return BottomPanelWidget;};
	TArray<TSharedPtr<SBuildingCard>>* GetSpawnableCards () {return  &SpawnableCards;};
	
	
	// Functions
	bool GenerateCards ();
	bool AddCardsToGrid(int NumRows );
	

	

private:

	/* Data Variables */
	float Width;
	float Height;
	TMap<int32, USpawnable*>*Spawnables;

	/** Reference */
	
	TSharedPtr<class SBottomBuildingsPanel> BottomPanelWidget;
	TArray<TSharedPtr<SBuildingCard>> SpawnableCards;
	
	
};



