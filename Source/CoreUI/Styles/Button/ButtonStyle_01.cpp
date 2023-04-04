#include "ButtonStyle_01.h"

#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> FCustomButtonStyle::StyleSet = nullptr;

FCustomButtonStyle::FCustomButtonStyle()
{
	// Set up the default button appearance here
	// Set the button's background color to red
	//BackgroundColor = FSlateColor(FLinearColor::Red);
}

const FName FCustomButtonStyle::TypeName("FCustomButtonStyle");

const FCustomButtonStyle& FCustomButtonStyle::GetDefault()
{
	static FCustomButtonStyle Default;
	return Default;
}

void FCustomButtonStyle::Initialize()
{
	if (!StyleSet.IsValid())
	{
		StyleSet = MakeShared<FSlateStyleSet>(FCustomButtonStyle::TypeName);
		StyleSet->SetContentRoot(FPaths::ProjectPluginsDir() / TEXT("YourPluginName") / TEXT("Resources"));

		// Set up the button appearance here
	}

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
}

void FCustomButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
	ensure(StyleSet.IsUnique());
	StyleSet.Reset();
}


void FCustomButtonStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}


FCustomButtonStyle::~FCustomButtonStyle()
{
	
}

#undef IMAGE_BRUSH
