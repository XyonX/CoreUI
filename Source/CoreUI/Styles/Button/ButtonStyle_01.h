#pragma once

#include "Styling/SlateStyle.h"
#include "Styling/SlateTypes.h"

class COREUI_API FCustomButtonStyle : public FButtonStyle
{
public:
	FCustomButtonStyle();

	static const FName TypeName;
	static const FCustomButtonStyle& GetDefault();
	
	static TSharedPtr<FSlateStyleSet> StyleSet;

	static void Initialize();
	static void Shutdown();
	static void ReloadTextures();

	virtual ~FCustomButtonStyle() ;
	
};
