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
	//UFont* MyUFont = LoadObject<UFont>(nullptr, TEXT("/Game/MyFont.MyFont"));
	//FSlateFontInfo MySlateFontInfo(MyUFont);

	//UFont* MyUFont = LoadObject<UFont>(nullptr, TEXT("/Game/MyFont.MyFont"));
	//TSharedPtr<const FCompositeFont> MyCompositeFont = FCompositeFont::Get().GetCompositeFont(MyUFont);
	//FSlateFontInfo MySlateFontInfo(MyCompositeFont, 16, FName("Regular"), FFontOutlineSettings());

	//FTypeface Typeface;
	//Typeface.Fonts.Add();

	// Create a new FCompositeFont object using Typeface
	//TSharedPtr<const FCompositeFont> CompositeFont = MakeShared<const FCompositeFont>();
	//CompositeFont->

	// Create a new FSlateFontInfo object using CompositeFont
	//FSlateFontInfo FontInfo(CompositeFont, 12, FName("Regular"));
	
}



TSharedRef<SWidget> UDebug_Item_Widget::RebuildWidget()
{
		SAssignNew(Widget,SDebug_Item,Widget_Width,Widget_Height)
	      .VarName(VariableName)
	      .VarValue(VariableValue)
		  .NameInfo(NameFontInfo)
	      .ValueInfo(ValueFOntInfo);

	return DebugContainerWidget.ToSharedRef();
	
}

void UDebug_Item_Widget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	DebugContainerWidget.Reset();
}
