﻿#include "LabHUD.h"

#include "Blueprint/UserWidget.h"
#include "Labyrinth/UI/GameOverlay.h"

ALabHUD::ALabHUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALabHUD::BeginPlay()
{
	Super::BeginPlay();
	checkf(GameOverlayClass, TEXT("[ALabHUD - BeginPlay: GameOverlayClass is not valid]"));

	GameOverlay = CreateWidget<UGameOverlay>(GetOwningPlayerController(), GameOverlayClass);
	checkf(GameOverlay, TEXT("[ALabHUD - BeginPlay: GameOverlay is not valid]"));

	GameOverlay->AddToViewport();
}

void ALabHUD::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALabHUD::ShowInitialStory()
{
}

void ALabHUD::HideMessage() const
{
	if (GameOverlay)
	{
		GameOverlay->HideMessage();
	}
}

void ALabHUD::ShowJumpScare() const
{
	if (GameOverlay)
	{
		GameOverlay->StartJumpScareAnimation();
	}
}

void ALabHUD::ShowGameOver() const
{
	if (GameOverlay)
	{
		GameOverlay->ShowGameOver();
	}
}

void ALabHUD::ShowMessage(const FString& Message) const
{
	if (GameOverlay)
	{
		const FText MessageText = FText::FromString(Message);
		GameOverlay->SetMessage(MessageText);
	}
}

void ALabHUD::ShowRemainingText(const FString& Message) const
{
	if (GameOverlay)
	{
		const FText TorchText = FText::FromString(Message);
		GameOverlay->SetRemainingTorchText(TorchText);
	}
}
