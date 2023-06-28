// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class USpawnable;
class SGridPanel;
class SScrollBox;

class COREUI_API SBottomBuildingsPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBottomBuildingsPanel)
	{}
	
	SLATE_ARGUMENT(float, SBHeight)
	SLATE_ARGUMENT(float, SBWidth)
	SLATE_END_ARGS()
	
	SBottomBuildingsPanel();

	
	void Construct(const FArguments& InArgs);

	
	TSharedRef<SWidget> BuildUI();


	/** Setter && Getters */ 

	//pure Data 
	void SetSize_BoxHeight(float InHeight);
	void SetSize_BoxWidth(float InWidth );

	//References]
	TSharedPtr<SOverlay> GetOverlay () {return MainOverlay;};
	TSharedPtr<SBox>  GetSizeBox () {return BottomSizeBox;};
	TSharedPtr<SScrollBox> GetScrollBox() {return BottomScrollBox;};
	TSharedPtr<SGridPanel> GetGridPanel () {return  BottomGridPanel;};
	


private:

	//Data Variables
	float Size_BoxHeight;
	float Size_BoxWidth;

	// References
	TSharedPtr<SOverlay> MainOverlay;
	TSharedPtr<SBox> BottomSizeBox;
	TSharedPtr<SScrollBox> BottomScrollBox;
	TSharedPtr<SGridPanel> BottomGridPanel;
	
	
};

