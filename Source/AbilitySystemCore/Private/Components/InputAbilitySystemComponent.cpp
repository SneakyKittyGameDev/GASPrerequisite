// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InputAbilitySystemComponent.h"


UInputAbilitySystemComponent::UInputAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInputAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInputAbilitySystemComponent::AbilityInputPressed(FGameplayTag Tag)
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.IsActive() && AbilitySpec.DynamicAbilityTags.HasTagExact(Tag))
		{
			TryActivateAbility(AbilitySpec.Handle);
			AbilitySpecInputPressed(AbilitySpec);
		}
	}
}

void UInputAbilitySystemComponent::AbilityInputReleased(FGameplayTag Tag)
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.IsActive() && AbilitySpec.DynamicAbilityTags.HasTagExact(Tag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}
