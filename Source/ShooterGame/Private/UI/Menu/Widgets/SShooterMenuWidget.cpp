// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "SShooterMenuWidget.h"

SShooterMenuWidget::SShooterMenuWidget()
{
	FString Text = TEXT("主菜单");
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
	//构建UI 声明式的语法
	ChildSlot
	[
		//第一层
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			// 包含标题和左右菜单容器
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
				//包含标题
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					//包含标题背景图
					SNew(SOverlay)
					+ SOverlay::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Fill)
					[			
						SNew(SBox) //Box只能有一个，不能添加Slot
						//指定标题背景图的大小
						.WidthOverride(MenuHeaderWidth)
						.HeightOverride(MenuHeaderHeight)
						[
							SNew(SImage)
						]
					]
					//包含标题文字
					+ SOverlay::Slot()
					.HAlign(HAlign_Left)//跟上面的Overlay保持一致
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
							//按照代理的方式给它赋值
							.Text(this,&SShooterMenuWidget::GetMenuTitle)
						]
					]
				]
			]
		]	
	];//加上分号表示整个ChildSlot是一个语句
}

FText SShooterMenuWidget::GetMenuTitle() const
{
	return CurrentMenuTitle;
}



