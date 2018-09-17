// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SHOOTERGAME_API SShooterMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SShooterMenuWidget)
		:_PlayerOwner()
	{
	
	}
	SLATE_ARGUMENT(TWeakObjectPtr<ULocalPlayer>, PlayerOwner)
	SLATE_END_ARGS()
		
	SShooterMenuWidget();
	virtual ~SShooterMenuWidget();

	void Construct(const FArguments& InArgs);
	FText GetMenuTitle() const;
private:
	TWeakObjectPtr<ULocalPlayer> PlayerOwner;

	float MenuHeaderWidth;

	float MenuHeaderHeight;

	FText CurrentMenuTitle;


};











