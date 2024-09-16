// Copyright 2024, Dakota Dawe, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "InputGameplayAbility.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputPressed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInputReleased);
UCLASS()
class ABILITYSYSTEMCORE_API UInputGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	FGameplayTag InputTag;
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
	void OnInputPressed();
	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
	void OnInputReleased();

	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
};
