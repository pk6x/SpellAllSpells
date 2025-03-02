// Copyright pk6x.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SASAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API USASAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void
	AbilityActorInfoSet();

protected:
	void
	EffectApplied(UAbilitySystemComponent* abilitySystemComponent,
	              const FGameplayEffectSpec& effectSpec,
	              FActiveGameplayEffectHandle activeEffectHandle);
};
