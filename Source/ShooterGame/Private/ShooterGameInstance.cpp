// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "UI/Menu/ShooterMainMenu.h"
#include "ShooterGameInstance.h"

void UShooterGameInstance::Init()
{
	Super::Init();
	TickDelegate = FTickerDelegate::CreateUObject(this, &UShooterGameInstance::Tick);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

bool UShooterGameInstance::Tick(float DeltaSeconds)
{
	static bool bExecuted = false; //���徲̬��������Ϊ������ִ��һ��
	if (!bExecuted)
	{	
		BeginMainMenuState();
		bExecuted = true;
	}
	return true;
}

void UShooterGameInstance::BeginMainMenuState()
{
	MainMenuUI = MakeShareable(new FShooterMainMenu);

	ULocalPlayer* const Player = GetFirstGamePlayer();
	MainMenuUI->Construct(this, Player);
	MainMenuUI->AddMenuToGameViewport();
}








