// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "InputAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABILITYSYSTEMCORE_API UInputAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInputAbilitySystemComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartingAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartingEffects;
	
	virtual void BeginPlay() override;

public:
	void AddAbility(const TSubclassOf<UGameplayAbility> Ability);
	void AddAbilities(TArray<TSubclassOf<UGameplayAbility>> Abilities);

	void AddEffect(const TSubclassOf<UGameplayEffect> Effect);
	void AddEffects(TArray<TSubclassOf<UGameplayEffect>> Effects);
	
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	void AbilityInputPressed(FGameplayTag Tag);
	void AbilityInputReleased(FGameplayTag Tag);
};
