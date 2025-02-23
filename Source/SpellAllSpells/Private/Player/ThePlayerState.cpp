// Copyight pk6x.


#include "Player/ThePlayerState.h"

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AbilitySystem/SASAttributeSet.h"

AThePlayerState::
AThePlayerState()
{
	abilitySystemComponent =
		CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	attributeSet = CreateDefaultSubobject<USASAttributeSet>("Attributes");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AThePlayerState::
GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}
