// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COREUI_API SMainMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenu)
		{
		}

	SLATE_END_ARGS()

	SMainMenu();

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


protected:

	float Screen_Width ;
	float Screen_Height ;

	TSharedPtr<SBox>RootBox;

	TSharedPtr<SHorizontalBox>Section_Header;
	TSharedPtr<SHorizontalBox>Section_Mid;
	TSharedPtr<SHorizontalBox>Section_Footer;
	
	TSharedPtr<SVerticalBox>Section_SideBar_Left;
	TSharedPtr<SVerticalBox>Section_SideBar_Right;
	
};
