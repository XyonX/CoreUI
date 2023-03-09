// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "CoreUI/Slate/CompoundWidgets/Debug_Item.h"
#include "Debug_Item_Widget.generated.h"

/**
 * 
 */
UCLASS()
class COREUI_API UDebug_Item_Widget : public UWidget
{
	GENERATED_BODY() 
public:
	UDebug_Item_Widget(const FObjectInitializer& ObjectInitializer);
	UDebug_Item_Widget(const FObjectInitializer& ObjectInitializer,  FText Name , FText Value);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	TSharedPtr<SDebug_Item> DebugContainerWidget ;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UMG")
	FText  VariableName  ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UMG")
	FText  VariableValue;
};
