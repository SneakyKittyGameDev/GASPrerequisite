// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InputAbilitySystemComponent.h"
#include "Abilities/InputGameplayAbility.h"


UInputAbilitySystemComponent::UInputAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInputAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsOwnerActorAuthoritative())
	{
		AddAbilities(StartingAbilities);
		AddEffects(StartingEffects);
	}
}

void UInputAbilitySystemComponent::AddAbility(const TSubclassOf<UGameplayAbility> Ability)
{
	GiveAbility(FGameplayAbilitySpec(Ability));
}

void UInputAbilitySystemComponent::AddAbilities(TArray<TSubclassOf<UGameplayAbility>> Abilities)
{
	for (const TSubclassOf<UGameplayAbility> Ability : Abilities)
	{
		AddAbility(Ability);
	}
}

void UInputAbilitySystemComponent::AddEffect(const TSubclassOf<UGameplayEffect> Effect)
{
	FGameplayEffectContextHandle ContextHandle;
	const FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(Effect, 1.0f, ContextHandle);
	
	ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}

void UInputAbilitySystemComponent::AddEffects(TArray<TSubclassOf<UGameplayEffect>> Effects)
{
	for (const TSubclassOf<UGameplayEffect> Effect : Effects)
	{
		AddEffect(Effect);
	}
}

void UInputAbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);
	if (const UInputGameplayAbility* Ability = Cast<UInputGameplayAbility>(AbilitySpec.Ability))
	{
		AbilitySpec.DynamicAbilityTags.AddTag(Ability->InputTag);
	}
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
