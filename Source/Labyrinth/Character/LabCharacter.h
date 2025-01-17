﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LabCharacter.generated.h"

class AWallTorch;
class AFireTorchPickup;
class UTorchComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class USphereComponent;
class UCameraShakeBase;

UCLASS()
class LABYRINTH_API ALabCharacter : public ACharacter
{
	GENERATED_BODY()

	/*
	 * Components
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	USkeletalMeshComponent* FirstPersonMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = true))
	UTorchComponent* TorchComponent;

	/*
	 * Game
	 */
	UPROPERTY(BlueprintReadOnly, Category = Game, meta = (AllowPrivateAccess = true))
	AWallTorch* WallTorch;

	UPROPERTY(BlueprintReadOnly, Category = Game, meta = (AllowPrivateAccess = true))
	AFireTorchPickup* FireTorchPickup;

	/*
	 * Dependencies
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	TSubclassOf<UCameraShakeBase> CameraShakeClass;
	
	UPROPERTY()
	FTimerHandle DashHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	float DashCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Config, meta = (AllowPrivateAccess = true))
	float DashForce;

	UPROPERTY(BlueprintReadOnly, Category = Game, meta = (AllowPrivateAccess = true))
	bool bCanDash;

	/*
	 * Callbacks
	 */
	UFUNCTION()
	void OnDashTimeout();

	UFUNCTION()
	void OnCharacterReceiveDamage(AActor* DamagedActor, float Damage,
	                              const UDamageType* DamageType, AController* InstigatedBy,
	                              AActor* DamageCauser);

	/*
	 * Character actions
	 */
	UFUNCTION(BlueprintCallable)
	void Dash();

	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void Look(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void Interact();

public:
	UFUNCTION(BlueprintCallable)
	void EquipTorch(ATorch* Torch);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_UpdateTorchAnimation();

	UFUNCTION(BlueprintCallable)
	void IncreaseTorch(int32 Value) const;

	UFUNCTION(BlueprintCallable)
	void ResetTorch() const;

	UFUNCTION(BlueprintCallable)
	void ReduceTorch(int32 Value) const;

	UFUNCTION(BlueprintCallable)
	void SetWallTorch(AWallTorch* NewWallTorch);

	UFUNCTION(BlueprintCallable)
	void SetPickup(AFireTorchPickup* TorchPickup);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	ALabCharacter();

	FORCEINLINE USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMeshComponent; }

	FORCEINLINE AWallTorch* GetLastWallTorch() const { return WallTorch; }
};
