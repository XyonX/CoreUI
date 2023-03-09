// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class COREUI_API SDebug_Item : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDebug_Item)
		{}

	SLATE_ARGUMENT(FText , VarName)
	SLATE_ARGUMENT(FText  , VarValue)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	// FUNCTIONS
	void SetName (FText in_Name );
	void  SetValue  (FText in_Value);

	template<typename T>
	FORCEINLINE typename TSharedPtr<T>::ElementType& SAssign(TSharedPtr<T>& Ptr, const typename TSharedPtr<T>::ElementType& Widget)
	{
		return *Ptr = Widget;
	}

private:
	
	TSharedPtr<SHorizontalBox> RootHorizontalBox ;
	FText VariableName ;
	FText VariableValue ;
	UTexture2D*BG  ;
};