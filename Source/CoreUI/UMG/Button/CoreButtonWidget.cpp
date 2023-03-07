#include "CoreUI/UMG/Button/CoreButtonWidget.h"
#include "CoreUI/Slate/LeafWidgets/Buttons/CoreButton.h"

UCoreButton::UCoreButton(const FObjectInitializer& ObjectInitializer)
				: Super(ObjectInitializer)
{
	// Set default values for properties
	ButtonText = "Button";
	ButtonImage = nullptr;
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