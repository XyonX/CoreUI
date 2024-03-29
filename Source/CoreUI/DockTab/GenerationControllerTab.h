﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_DELEGATE_RetVal(bool, FOnGenerateButtonClick)
DECLARE_DELEGATE_RetVal(bool, FOnButtonClick_Debug)

class COREUI_API SGenerationControllerTab : public SDockTab
{
public:
	SLATE_BEGIN_ARGS(SGenerationControllerTab) {}
	SLATE_END_ARGS()
	SGenerationControllerTab();
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	// Register the dockable tab
	static void RegisterTabSpawner();
	
	// Create an instance of the dockable tab
	static TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& SpawnTabArgs);


	//THIS NAME IS FOR  IDENTIFY THIS ACTS   AS A  IDENTIFIER
	static  FName TabName  ;
	//const FName TabName  =FName("ControllerTab");
	// Get the tab identifier
	FName GetTabIdentifier() const;

		
	static FOnGenerateButtonClick GenerateDelegate ;
	static FOnButtonClick_Debug DebugDelegate ;

	//getter
	 FORCEINLINE TSharedPtr<SVerticalBox> GetWidget () {return Widget; }


	static bool OnGenerateClick ();
	static bool OnDebug ();
	//TSharedPtr<SButton>GenerateButton ;

	TSharedPtr<FSlateBrush> SB_TabSwitcher ;
private:
	TSharedPtr<SHorizontalBox>MainHorizontalBox;
	TSharedPtr<SVerticalBox> Widget;
	TSharedPtr<SVerticalBox> TabSwitcher;
	
		
	
};
				