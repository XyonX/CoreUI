// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "CoreUI/UMG/Button/CoreButtonWidget.h"
#include "GameFramework/HUD.h"
#include "CoreUIHud.generated.h"

/**
 * 
 */
UCLASS()
class COREUI_API ACoreUIHud : public AHUD
{
	GENERATED_BODY()

public:
	ACoreUIHud();
	virtual void BeginPlay() override;
	TSharedPtr<	SCoreButton	> SlateButton  ;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="HUD")
	UCoreButton*UMGButton  ;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="HUD")
	UGameViewportClient  *  ViewportClient  ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite  ,  Category  ="HUD")
	UUserWidget* TheUI  ;



	//Variables
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HUD")
	UTexture2D*  ButtonTexture  ;
	
	
};
