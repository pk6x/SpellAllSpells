// Copyight pk6x.

#include "AbilitySystem/SASAbilitySystemComponent.h"

void
USASAbilitySystemComponent::
AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &USASAbilitySystemComponent::EffectApplied);
}

void
USASAbilitySystemComponent::
EffectApplied(UAbilitySystemComponent* abilitySystemComponent,
              const FGameplayEffectSpec& effectSpec,
              FActiveGameplayEffectHandle activeEffectHandle)
{
	FGameplayTagContainer tagContainer;
	
	effectSpec.GetAllAssetTags(tagContainer);

	for (const FGameplayTag& tag : tagContainer)
	{
		//TODO: Broadcast the tag to the Widget Controller

		const FString msg = FString::Printf(TEXT("GE Tag: %s"), *tag.ToString());
		
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, msg);
	}
}
