// Fill out your copyright notice in the Description page of Project Settings.


#include "GASTutorial/Public/PlayerPlayerState.h"
#include "Components/InputAbilitySystemComponent.h"

APlayerPlayerState::APlayerPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UInputAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->ReplicationMode = EGameplayEffectReplicationMode::Mixed;
	
}

UAbilitySystemComponent* APlayerPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
