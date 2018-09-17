#pragma once
//使用slate必须包含这两个
#include "SlateBasics.h"
#include "SlateExtras.h"
//#include "ShooterGameIntance.h"
#include "Public/ShooterGameInstance.h"

class SShooterMenuWidget;

class SHOOTERGAME_API FShooterMainMenu : public TSharedFromThis<FShooterMainMenu>,public FTickableGameObject
{
public:
	FShooterMainMenu();

	virtual ~FShooterMainMenu();
	
	void Construct(TWeakObjectPtr<UShooterGameInstance> _GameInstance,TWeakObjectPtr<ULocalPlayer> _PlayerOwner);

	void AddMenuToGameViewport();

	void RemoveMenuFromGameViewport();

	virtual void Tick(float DeltaSeconds) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;

	ULocalPlayer* GetPlayerOwner() const;

protected:
	TWeakObjectPtr<ULocalPlayer> PlayerOwner;

	TWeakObjectPtr<UShooterGameInstance> GameInstance;

	TSharedPtr<SShooterMenuWidget> MenuWidget;

	TSharedPtr<class SWeakWidget> MenuWidgetContainer;

	
};


