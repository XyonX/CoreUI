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
	//return SAssignNew(LoadingScreenWidget,SLoadingScreenLayout);
	// Create the LoadingScreenWidget and store it in the member variable.
	SAssignNew(LoadingScreenWidget, SLoadingScreenLayout);
	return LoadingScreenWidget.ToSharedRef();
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
		LoadingScreenWidget->SetStyle_StartButton(ButtonStyle_StartButton);
	}
}

void ULoadingScreenUI::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	LoadingScreenWidget.Reset();
	
}
