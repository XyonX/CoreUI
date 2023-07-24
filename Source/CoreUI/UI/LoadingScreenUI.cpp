// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingScreenUI.h"
#include "CoreUI/Slate/LoadingScreen/SLoadingScreenLayout.h"

void ULoadingScreenUI::NativeConstruct()
{
	Super::NativeConstruct();
	RebuildWidget();
}

TSharedRef<SWidget> ULoadingScreenUI::RebuildWidget()
{
	return SAssignNew(LoadingScreenWidget,SLoadingScreenLayout);
}

void ULoadingScreenUI::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if(LoadingScreenWidget.IsValid())
	{
		LoadingScreenWidget->SetScreen_Height(ScreenHeight);
		LoadingScreenWidget->SetScreen_Width(ScreenWidth);
		LoadingScreenWidget->SetBrush_StartButton(Brush_StartButton);
		LoadingScreenWidget->SetBrush_Background(Brush_Background);
	}
}

void ULoadingScreenUI::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	LoadingScreenWidget.Reset();
	
}
