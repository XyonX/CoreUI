#pragma once
#include "Widgets/Input/SButton.h"
#include "Slate/DeferredCleanupSlateBrush.h"

/**
 * this is a custom button class inheriting from SButton class
 * the macro SLATE_BEGIN_ARGS() starts the button declaration'
 * 
 *
 * 
 */
class SCoreButton : public SButton
{
public:
	SLATE_BEGIN_ARGS(SCoreButton)
		: _ButtonText(TEXT("Button"))
	{}
 
	SLATE_ARGUMENT(FString, ButtonText)
	SLATE_ARGUMENT(UTexture2D*,ButtonImage)
	
	SLATE_EVENT(FOnClicked, OnClicked)
 
	SLATE_END_ARGS()
 
	void Construct( const FArguments& InArgs);

	void SetText(FString& NewText) ;
	void SetImage( UTexture2D* NewImage);

	// helper function
	TSharedPtr<FSlateBrush> Convert_UT2D_SlateBrush (UTexture2D* NewImage);
 
private:
	FString ButtonText;
	//FSlateBrush ButtonImage ;
	TSharedPtr<FSlateBrush>  ButtonImage ;
	TSharedPtr<SVerticalBox>RootVertBox;
	TSharedPtr<STextBlock> TextBlock;
	TSharedPtr<SImage> ImageWidget;
	

	FOnClicked OnClicked;
};