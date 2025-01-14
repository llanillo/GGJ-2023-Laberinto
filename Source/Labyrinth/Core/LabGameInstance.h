﻿#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LabGameInstance.generated.h"

class ASpawnTriggerBox;

UCLASS(BlueprintType)
class LABYRINTH_API ULabGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	FString WallTorchRechargeMessage;

	UPROPERTY(BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	FString WallTorchLightUpeMessage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	FName MainMenuLevelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	FName LabLevelName;

public:
	ULabGameInstance();

	FORCEINLINE const FName& GetMenuLevelName() const { return MainMenuLevelName; }

	FORCEINLINE const FName& GetPrincipalLevelName() const { return LabLevelName; }

	FORCEINLINE const FString& GetWallTorchRechargeMessage() const { return WallTorchRechargeMessage; }

	FORCEINLINE const FString& GetWallTorchLightUpMessage() const { return WallTorchLightUpeMessage; }
};
