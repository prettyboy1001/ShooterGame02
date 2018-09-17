// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Engine/GameInstance.h"
#include "ShooterGameInstance.generated.h"

/**
 * 
 */
//Ç°ÏòÉùÃ÷
class FShooterMainMenu;
UCLASS()
class SHOOTERGAME_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	bool Tick(float DeltaSeconds);

private:
	void BeginMainMenuState();

	TSharedPtr<FShooterMainMenu> MainMenuUI;
	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;
};





