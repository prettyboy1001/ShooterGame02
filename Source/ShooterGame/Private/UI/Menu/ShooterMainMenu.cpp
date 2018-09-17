
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
	//��ȫ����������ÿ�
	MenuWidget.Reset();
	MenuWidgetContainer.Reset();
	//�����˵�UI�������

	if (GEngine && GEngine->GameViewport)
	{
		//�ڹ��캯�������SMenuWidget������������
		SAssignNew(MenuWidget, SShooterMenuWidget)
			.Cursor(EMouseCursor::Default)
			.PlayerOwner(GetPlayerOwner());	
		//��MenuWidget��ֵ
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
