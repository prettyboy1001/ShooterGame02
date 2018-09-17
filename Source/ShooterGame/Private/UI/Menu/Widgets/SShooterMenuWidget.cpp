// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "SShooterMenuWidget.h"

SShooterMenuWidget::SShooterMenuWidget()
{
	FString Text = TEXT("���˵�");
	CurrentMenuTitle = FText::FromString(Text);



}

SShooterMenuWidget::~SShooterMenuWidget()
{

}

void SShooterMenuWidget::Construct(const FArguments& InArgs)
{
	PlayerOwner = InArgs._PlayerOwner;

	FLinearColor MenuTitleTextColor = FLinearColor(155, 164, 182);

	MenuHeaderWidth = 287.0f;
	MenuHeaderHeight = 62.0f;
	//����UI ����ʽ���﷨
	ChildSlot
	[
		//��һ��
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			// ������������Ҳ˵�����
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
				//��������
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					//�������ⱳ��ͼ
					SNew(SOverlay)
					+ SOverlay::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Fill)
					[			
						SNew(SBox) //Boxֻ����һ�����������Slot
						//ָ�����ⱳ��ͼ�Ĵ�С
						.WidthOverride(MenuHeaderWidth)
						.HeightOverride(MenuHeaderHeight)
						[
							SNew(SImage)
						]
					]
					//������������
					+ SOverlay::Slot()
					.HAlign(HAlign_Left)//�������Overlay����һ��
					.VAlign(VAlign_Fill)
					[
						SNew(SBox)
						.WidthOverride(MenuHeaderWidth)
						.HeightOverride(MenuHeaderHeight)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.ColorAndOpacity(MenuTitleTextColor)
							//���մ���ķ�ʽ������ֵ
							.Text(this,&SShooterMenuWidget::GetMenuTitle)
						]
					]
				]
			]
		]	
	];//���Ϸֺű�ʾ����ChildSlot��һ�����
}

FText SShooterMenuWidget::GetMenuTitle() const
{
	return CurrentMenuTitle;
}



