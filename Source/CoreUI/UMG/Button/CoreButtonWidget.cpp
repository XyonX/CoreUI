#include "CoreUI/UMG/Button/CoreButtonWidget.h"
#include "CoreUI/Slate/LeafWidgets/Buttons/CoreButton.h"

UCoreButton::UCoreButton(const FObjectInitializer& ObjectInitializer)
				: Super(ObjectInitializer)
{
	
}

UCoreButton::UCoreButton(const FObjectInitializer& ObjectInitializer ,UTexture2D* Image ,FString Text)
				: Super(ObjectInitializer)
{
	// Set default values for properties
	ButtonText = Text;
	ButtonImage = Image;
}

void UCoreButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	// Update the widget with the latest property values
	if (ButtonWidget.IsValid())
	{
		ButtonWidget->SetText(ButtonText);
		ButtonWidget->SetImage(ButtonImage);
	}	// Update the widget with the latest property values
	if (ButtonWidget.IsValid())
	{
		ButtonWidget->SetText(ButtonText);
		ButtonWidget->SetImage(ButtonImage);
	}
}

TSharedRef<SWidget> UCoreButton::RebuildWidget()
{
	ButtonWidget = SNew(SCoreButton)
		.ButtonText(ButtonText) // Convert FText to FString using FromString() function
		.ButtonImage(ButtonImage)
		//.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, OnButtonClicked));
		.OnClicked(OnClicked);

	

	return ButtonWidget.ToSharedRef();
	
}

void UCoreButton::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	ButtonWidget.Reset();
}
