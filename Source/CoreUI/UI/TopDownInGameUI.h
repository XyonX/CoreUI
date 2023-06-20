#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/SizeBox.h"
#include "TopDownInGameUI.Generated.h"

UCLASS()
class UTopDownInGameUI : public UUserWidget
{
	GENERATED_BODY()

public:
	// Called when the widget is constructed on the screen
	virtual void NativeConstruct() override;

	// Optional: Override the NativeTick function for per-frame updates
	// virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// Optional: Add custom functions and properties
	// void MyCustomFunction();


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USizeBox*RootSizeBox;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UHorizontalBox*HorizontalBox;
	


};