#include "TestUMG.h"

#include "CoreUI/Slate/Cards/SBuildingCard.h"

UTestUMG::UTestUMG(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}

void UTestUMG::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if(BuildingCard.IsValid())
	{
		BuildingCard->SetBrush(BuildingImage);
	}
}

TSharedRef<SWidget> UTestUMG::RebuildWidget()
{

	SAssignNew(  BuildingCard,SBuildingCard);
	return BuildingCard.ToSharedRef();
}

void UTestUMG::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	BuildingCard.Reset();
}

void UTestUMG::SetBuildingImage(UTexture2D* Texture)
{
	BuildingImage=Texture;
}
