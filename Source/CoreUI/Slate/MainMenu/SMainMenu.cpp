// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenu.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SMainMenu::SMainMenu()
	:
	Screen_Height(),
	Screen_Width()
{
}

void SMainMenu::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		SAssignNew(RootBox, SBox)
		.WidthOverride_Lambda([this]() -> float {
			return Screen_Width;
		})
		.HeightOverride_Lambda([this]() -> float {
			return Screen_Height;
		})
		[
			SNew(SVerticalBox)

			// Header
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Top)
			.MaxHeight(Screen_Height/4.0f)
			[
					SAssignNew(Section_Header,SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(SImage)
					]
			]
			
			//Mid
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			.AutoHeight()
			[
				SAssignNew(Section_Mid, SHorizontalBox)
					+SHorizontalBox::Slot()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Left)
					.FillWidth(1.0f) // First sidebar takes the left side
						[
						SAssignNew(Section_SideBar_Left,SVerticalBox)
						// First Sidebar content goes here
						]
					+SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Center)
						.FillWidth(3.0f) // Main content takes the center
						[
						SNew(SImage)
						// Main Content goes here
						]
					+SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Right)
						.FillWidth(1.0f) // Second sidebar takes the right side
						[
						SAssignNew(Section_SideBar_Right,SVerticalBox)
						// Second Sidebar content goes here
						]
			]
			
			//Footer
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Bottom)
			.MaxHeight(Screen_Height/4.0f)
			[
					SAssignNew(Section_Footer,SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(SImage)
					]
			]
		]
		

	];
	
	
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
