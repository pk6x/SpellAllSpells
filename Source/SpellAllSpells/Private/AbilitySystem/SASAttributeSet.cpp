// Copyight pk6x.

#include "AbilitySystem/SASAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotion_Base.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

USASAttributeSet::
USASAttributeSet()
{
	Inithealth(50.f);
	InitmaxHealth(100.f);
	Initmana(50.f);
	InitmaxMana(100.f);
}

void
USASAttributeSet::
GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, maxHealth, COND_None, REPNOTIFY_Always)

	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USASAttributeSet, maxMana, COND_None, REPNOTIFY_Always)
}

void
USASAttributeSet::
PreAttributeChange(const FGameplayAttribute& attribute,
                   float& newValue)
{
	Super::PreAttributeChange(attribute, newValue);

	if (attribute == GethealthAttribute())
	{
		newValue = FMath::Clamp(newValue, 0.f, GetmaxHealth());
	}

	if (attribute == GetmanaAttribute())
	{
		newValue = FMath::Clamp(newValue, 0.f, GetmaxMana());
	}
}

void
USASAttributeSet::
SetEffectProperties(const struct FGameplayEffectModCallbackData& data,
                    FEffectProperties& effectProperties)
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS)

	effectProperties.effectContextHandle = data.EffectSpec.GetContext();
	effectProperties.sourceASC = effectProperties.effectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(effectProperties.sourceASC)
		&& effectProperties.sourceASC->AbilityActorInfo.IsValid()
		&& effectProperties.sourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		effectProperties.sourceAvatarActor = effectProperties.sourceASC->AbilityActorInfo->AvatarActor.Get();

		effectProperties.sourceController = effectProperties.sourceASC->AbilityActorInfo->PlayerController.Get();

		if (effectProperties.sourceController == nullptr
			&& effectProperties.sourceAvatarActor != nullptr)
		{
			if (const APawn* pawn = Cast<APawn>(effectProperties.sourceAvatarActor))
			{
				effectProperties.sourceController = pawn->GetController();
			}
		}

		if (effectProperties.sourceController)
		{
			effectProperties.sourceCharacter = Cast<ACharacter>(effectProperties.sourceController->GetPawn());
		}
	}

	if (data.Target.AbilityActorInfo.IsValid()
		&& data.Target.AbilityActorInfo->AvatarActor.IsValid())

	{
		effectProperties.targetAvatarActor = data.Target.AbilityActorInfo->AvatarActor.Get();

		effectProperties.targetController = data.Target.AbilityActorInfo->PlayerController.Get();

		effectProperties.targetCharacter = Cast<ACharacter>(effectProperties.targetAvatarActor);

		effectProperties.targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(
			 effectProperties.targetAvatarActor);
	}
}

void
USASAttributeSet::
PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& data)
{
	Super::PostGameplayEffectExecute(data);

	FEffectProperties effectProps;
	SetEffectProperties(data, effectProps);
}

void
USASAttributeSet::
OnRep_Health(const FGameplayAttributeData& oldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, health, oldHealth)
}

void
USASAttributeSet::
OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, maxHealth, oldMaxHealth)
}

void
USASAttributeSet::
OnRep_Mana(const FGameplayAttributeData& oldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, mana, oldMana)
}

void
USASAttributeSet::
OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USASAttributeSet, maxMana, oldMaxMana)
}
