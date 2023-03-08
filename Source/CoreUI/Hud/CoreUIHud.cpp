// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreUI/Hud/CoreUIHud.h"
#include  "CoreUI/UMG/Button/CoreButtonWidget.h"
#include "Components/PanelWidget.h"

ACoreUIHud::ACoreUIHud()
{
	//UMGButton  =  CreateWidget<UCoreButton>(GetOwningPlayerController(),UCoreButton::StaticClass() );
	//TheUI  =  CreateWidget<UUserWidget>(GetOwningPlayerController(), UUserWidget::StaticClass());
	
}

void ACoreUIHud::BeginPlay()
{
	Super::BeginPlay();
	SlateButton  = SNew(SCoreButton)
					.ButtonImage(ButtonTexture)
					.ButtonText("	TEST BUTTON  ");
	ViewportClient  =  GetWorld()->GetGameViewport();
	if(ViewportClient)
	{
		if(SlateButton)
		{
			ViewportClient->AddViewportWidgetContent(SlateButton.ToSharedRef());
			
		}
		
	}
	
}
