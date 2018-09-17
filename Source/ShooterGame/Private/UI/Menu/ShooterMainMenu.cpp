
#include "ShooterGame.h"
#include "ShooterGameInstance.h"
#include "Widgets/SShooterMenuWidget.h"
#include "ShooterMainMenu.h"


FShooterMainMenu::FShooterMainMenu()
{
	
}

FShooterMainMenu::~FShooterMainMenu()
{


}
void FShooterMainMenu::Tick(float DeltaSeconds) 
{ 

}
bool FShooterMainMenu::IsTickable() const
{
	return true;
}

TStatId FShooterMainMenu::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FShooterMainMenu, STATGROUP_Tickables);
}

ULocalPlayer* FShooterMainMenu::GetPlayerOwner() const
{
	return PlayerOwner.Get();
}

void FShooterMainMenu::Construct(TWeakObjectPtr<UShooterGameInstance> _GameInstance, TWeakObjectPtr<ULocalPlayer> _PlayerOwner)
{
	GameInstance = _GameInstance;
	PlayerOwner = _PlayerOwner;
	//安全性起见，先置空
	MenuWidget.Reset();
	MenuWidgetContainer.Reset();
	//创建菜单UI管理对象

	if (GEngine && GEngine->GameViewport)
	{
		//在构造函数里面把SMenuWidget真正构建起来
		SAssignNew(MenuWidget, SShooterMenuWidget)
			.Cursor(EMouseCursor::Default)
			.PlayerOwner(GetPlayerOwner());	
		//给MenuWidget赋值
		SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(MenuWidget);
	}




}


void FShooterMainMenu::AddMenuToGameViewport()
{
	if(GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* const GVC = GEngine->GameViewport;
		GVC->AddViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
	}
}

void FShooterMainMenu::RemoveMenuFromGameViewport()
{
	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* const GVC = GEngine->GameViewport;
		GVC->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
	}

}
