// Copyright 2024, Dakota Dawe, All rights reserved

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
	// This will auto give starting abilities when the player controller is set
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	bool bAutoGiveStartingAbilities {true};
	// This will auto give starting effects when the player controller is set
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	bool bAutoGiveStartingEffects {true};
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartingAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartingPassiveAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartingEffects;
	
	virtual void BeginPlay() override;
	virtual void OnPlayerControllerSet() override;

public:
	void GiveStartingAbilities();
	void GiveStartingEffects();
	
	void AddAbility(const TSubclassOf<UGameplayAbility>& Ability, bool bAutoActivateAbility = false);
	void AddAbilities(const TArray<TSubclassOf<UGameplayAbility>>& Abilities, bool bAutoActivateAbility = false);

	void AddEffect(const TSubclassOf<UGameplayEffect>& Effect);
	void AddEffects(const TArray<TSubclassOf<UGameplayEffect>>& Effects);
	
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	void AbilityInputPressed(const FGameplayTag& Tag);
	void AbilityInputReleased(const FGameplayTag& Tag);
};
