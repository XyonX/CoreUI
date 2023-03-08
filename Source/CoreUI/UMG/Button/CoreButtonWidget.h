#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "CoreUI/Slate/LeafWidgets/Buttons/CoreButton.h"
#include "CoreButtonWidget.generated.h"

UCLASS()
class COREUI_API UCoreButton : public UButton
{
	GENERATED_BODY()

public:
	UCoreButton(const FObjectInitializer& ObjectInitializer);
	UCoreButton(const FObjectInitializer& ObjectInitializer ,UTexture2D* Image ,FString Text );
	
	//virtual void NativeConstruct() override;

	virtual void SynchronizeProperties() override;
	virtual TSharedRef<SWidget> RebuildWidget() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyButton")
	FString ButtonText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyButton")
	FName ButtonName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyButton")
	UTexture2D* ButtonImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyButton")
	FLinearColor ButtonColor;

	//UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnClicked OnClicked;

private:
	TSharedPtr<class SCoreButton> ButtonWidget;
	
};
