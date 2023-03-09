// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug_Item_Widget.h"


UDebug_Item_Widget::UDebug_Item_Widget(const FObjectInitializer& ObjectInitializer)  : Super(ObjectInitializer)
{
	
}

UDebug_Item_Widget::UDebug_Item_Widget( const FObjectInitializer& ObjectInitializer, FText Name, FText Value)  :  Super(ObjectInitializer)
{
	VariableName  =Name;
	VariableValue = Value;
}



TSharedRef<SWidget> UDebug_Item_Widget::RebuildWidget()
{
	DebugContainerWidget =SNew(SDebug_Item)
							.VarName(VariableName)
							.VarValue(VariableValue);

	return DebugContainerWidget.ToSharedRef();
	
}

void UDebug_Item_Widget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	DebugContainerWidget.Reset();
}
