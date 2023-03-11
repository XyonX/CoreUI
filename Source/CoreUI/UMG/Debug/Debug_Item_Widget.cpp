// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug_Item_Widget.h"


UDebug_Item_Widget::UDebug_Item_Widget(const FObjectInitializer& ObjectInitializer)  : Super(ObjectInitializer)
{
	
}
UDebug_Item_Widget::UDebug_Item_Widget( const FObjectInitializer& ObjectInitializer, FText Name, FText Value)  :  Super(ObjectInitializer)
{
	VariableName  =Name;
	VariableValue = Value;
	TSharedPtr<const FCompositeFont> MyCompositeFont = MakeShared<FCompositeFont>();
	Widget_Width = 200;
	Widget_Height =  20;
	NameBG=FLinearColor(1.0,0.0,1.0,1.0);
	ValueBG =FLinearColor(0.0,1.0,1.0,1.0);

	FSlateBrush*NAMEB = &NameBrushAsset;
	NameBrush  = MakeShareable(NAMEB);

	FSlateBrush*VALUEB =& ValueBrushAsset;
	ValueBrush =MakeShareable((VALUEB));
	
}
TSharedRef<SWidget> UDebug_Item_Widget::RebuildWidget()
{
		//SAssignNew(Widget,SDebug_Item,Widget_Width,Widget_Height)
		SAssignNew(DebugContainerWidget,SDebug_Item)
	      .VarName(VariableName)
	      .VarValue(VariableValue)
		  .MaxHeight(Widget_Height)
		  .MaxWidth(Widget_Width)
		  .NameBGColor(NameBG)
		  .ValueBGColor(ValueBG)
	      .NameBGBrush(NameBrush)
		  .ValueBGBrush(ValueBrush);
		
	

	return DebugContainerWidget.ToSharedRef();
	
}

void UDebug_Item_Widget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	DebugContainerWidget.Reset();
}
