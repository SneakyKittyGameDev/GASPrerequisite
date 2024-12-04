// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "PlayerPlayerState.generated.h"

class UInputAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GASTUTORIAL_API APlayerPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	APlayerPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAbilitySystemComponent> AbilitySystemComponent;
};
