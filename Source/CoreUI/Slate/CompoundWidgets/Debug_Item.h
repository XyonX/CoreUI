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
	SLATE_ARGUMENT(FSlateFontInfo ,  NameInfo)
	SLATE_ARGUMENT(FSlateFontInfo ,  ValueInfo)
	SLATE_ARGUMENT(FText  , VarValue)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	SDebug_Item(int in_Width,  int in_Height );


	// FUNCTIONS
	void SetName (FText in_Name );
	void  SetValue  (FText in_Value);

	template<typename T>
	FORCEINLINE typename TSharedPtr<T>::ElementType& SAssign(TSharedPtr<T>& Ptr, const typename TSharedPtr<T>::ElementType& Widget)
	{
		return *Ptr = Widget;
	}

private:
	int  RootHeight ;
	int  RootWidth ;
	TSharedPtr<SHorizontalBox> RootHorizontalBox ;
	
	
	
	
	

	
	

	//Name
	FText VariableName ;
	FLinearColor NameBGColor ;
	UTexture2D* NameBGTex ;
	FSlateFontInfo NameFontInfo ;

	//value
	FText VariableValue ;
	FLinearColor ValueBGColor  ;
	UTexture2D* ValueBGTex  ;
	FSlateFontInfo ValueFontInfo ;
	
	

public:
	// TOTAL SIZE 
	FORCEINLINE void SetWidth (int  Width) {   RootWidth = Width;}
	FORCEINLINE void SetHeight (int  Height) { RootHeight = Height;}

	//NAME
	FORCEINLINE void SetNameBG (FLinearColor Color )  {  NameBGColor= Color; }

	//VALUE
	FORCEINLINE void SetValueBG (FLinearColor Color )  { ValueBGColor= Color; }
};