// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "AbilitySystemEnhancedInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABILITYSYSTEMCORE_API UAbilitySystemEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAbilitySystemEnhancedInputComponent();
};
