#include"TopDownIngameScreen.h"
#include "Components/PanelWidget.h"
#include "CoreUI/Slate/Cards/SBuildingCard.h"
#include "Widgets/Layout/SGridPanel.h"
#include "CoreUI/Slate/CompoundWidgets/SBottomBuildingsPanel.h"


void UTopDownIngameScreen::NativeConstruct()
{
	Super::NativeConstruct();
	RebuildWidget();
	if(Spawnables)
	{
		GenerateCards();
		AddCardsToGrid(2);
	}
	
	
}

TSharedRef<SWidget> UTopDownIngameScreen::RebuildWidget()
{
	 return SAssignNew(BottomPanelWidget,SBottomBuildingsPanel);
}

void UTopDownIngameScreen::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	
	if(BottomPanelWidget.IsValid())
	{
		BottomPanelWidget->SetSize_BoxHeight(Height);
		BottomPanelWidget->SetSize_BoxWidth(Width);
		if(SpawnableCards.IsEmpty())
		{
			GenerateCards();
			AddCardsToGrid(2);
		}
	}
}

void UTopDownIngameScreen::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	BottomPanelWidget.Reset();
}


bool UTopDownIngameScreen::GenerateCards()
{
	for(const TPair<int32, USpawnable*>& Pair : *Spawnables)
	{
		int32 ID = Pair.Key;
		USpawnable*Item = Pair.Value;
		TSharedPtr<SBuildingCard> ImageTile = SNew(SBuildingCard);
		//.inTexture(Item->GetIcon());
		ImageTile->SetBrush(Item->GetIcon());
		Item->SetCard(ImageTile);
		SpawnableCards.Add(ImageTile);
		
	}
	return true;
}

bool UTopDownIngameScreen::AddCardsToGrid(int NumRows)
{
	TSharedPtr<SGridPanel> GP =BottomPanelWidget->GetGridPanel();

	int NumCols =(SpawnableCards.Num()/NumRows);
	if(SpawnableCards.Num()%NumRows!=0)
	{
		NumCols++;
	}
	
	int TileIndex=0;
	for (int32 RowIndex = 0;RowIndex < NumRows; RowIndex++)
	{
		for (int32 ColumnIndex = 0; ColumnIndex < NumCols ; ColumnIndex++)
		{
			GP->AddSlot(ColumnIndex, RowIndex)
			.Padding(5.0f)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SBox)
				.WidthOverride(50)
				.HeightOverride(50)
				[
					SpawnableCards[TileIndex]->AsShared()
				]
			];

			TileIndex++;
			if (!(TileIndex < SpawnableCards.Num()))
            {
                break;
            }
				
		}
	}

	return true;
}
