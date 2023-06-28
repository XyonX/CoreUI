#include "SBottomBuildingsPanel.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SBottomBuildingsPanel::SBottomBuildingsPanel()
	:Size_BoxHeight(),
	Size_BoxWidth()
	{
	
	}

void SBottomBuildingsPanel::Construct(const FArguments& InArgs)
{
	SetSize_BoxHeight(InArgs._SBHeight);
	SetSize_BoxWidth(InArgs._SBWidth);
	
	ChildSlot
	[
		BuildUI()
	];
	
}

TSharedRef<SWidget> SBottomBuildingsPanel::BuildUI()
{
	SAssignNew(MainOverlay, SOverlay)
	+ SOverlay::Slot()
	.HAlign(HAlign_Center)
	.VAlign(VAlign_Bottom)
	[
		SAssignNew(BottomSizeBox, SBox)
		.WidthOverride_Lambda([this]() -> float {
			return Size_BoxWidth;
		})
		[
			SAssignNew(BottomScrollBox, SScrollBox)
			.Orientation(Orient_Horizontal)
			.ScrollBarAlwaysVisible(true)
			.ScrollBarThickness(FVector2D(8.0f, 8.0f))
			+ SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SAssignNew(BottomGridPanel, SGridPanel)
				]
		]
	];

	return MainOverlay.ToSharedRef();
}

void SBottomBuildingsPanel::SetSize_BoxHeight(float InHeight)
{
	Size_BoxHeight =InHeight;
}
void SBottomBuildingsPanel::SetSize_BoxWidth(float InWidth)
{
	Size_BoxWidth=InWidth;
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
