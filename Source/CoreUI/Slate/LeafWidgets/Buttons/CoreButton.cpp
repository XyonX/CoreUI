#include "CoreButton.h"

#include "Slate/DeferredCleanupSlateBrush.h"
#include "Styling/SlateBrush.h"


void SCoreButton::Construct(const FArguments& InArgs)
{
	ButtonText = InArgs._ButtonText ;
	OnClicked = InArgs._OnClicked;
	ButtonImage = Convert_UT2D_SlateBrush(InArgs._ButtonImage);
	
	ChildSlot
	[    SNew(SVerticalBox)
		+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Padding(5.0f)
		
			[
				SNew(STextBlock)
					.Text(FText::FromString(ButtonText))
			]

		+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Padding(5.0f)
			[
				SNew(SImage)
					.Image(ButtonImage.Get())
			]
	];
}

void SCoreButton::SetText( FString& NewText)
{
	ButtonText = NewText;
	if (TextBlock.IsValid())
	{
		TextBlock->SetText(FText::FromString(NewText));
	}
}

void SCoreButton::SetImage( UTexture2D* NewImage)
{
	ButtonImage  =  Convert_UT2D_SlateBrush(NewImage);
	if (NewImage != nullptr)
	{
		if (ImageWidget.IsValid())
		{
			ImageWidget->SetImage(ButtonImage.Get());
		}
	}
}

TSharedPtr<FSlateBrush> SCoreButton::Convert_UT2D_SlateBrush(UTexture2D* NewImage)
{
	FSlateBrush* Brush = new FSlateBrush();
	Brush->SetResourceObject(NewImage);
	TSharedPtr<FSlateBrush>  Image  =MakeShareable(Brush);
	return Image;
}


