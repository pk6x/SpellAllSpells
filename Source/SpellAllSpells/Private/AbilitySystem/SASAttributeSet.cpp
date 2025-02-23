// Copyight pk6x.

#include "AbilitySystem/SASAttributeSet.h"
#include "Net/UnrealNetwork.h"

USASAttributeSet::
USASAttributeSet()
{
	Inithealth(100.f);
	InitmaxHealth(200.f);
	Initmana(40.f);
	InitmaxMana(100.f);
}

void USASAttributeSet::
GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, maxHealth, COND_None, REPNOTIFY_Always)

	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, maxMana, COND_None, REPNOTIFY_Always)
}

void USASAttributeSet::
OnRep_Health(const FGameplayAttributeData& oldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, health, oldHealth)
}

void USASAttributeSet::
OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, maxHealth, oldMaxHealth)
}

void USASAttributeSet::
OnRep_Mana(const FGameplayAttributeData& oldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, mana, oldMana)
}

void USASAttributeSet::
OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, maxMana, oldMaxMana);
}
