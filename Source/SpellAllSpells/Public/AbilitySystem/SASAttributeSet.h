// Copyright pk6x.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

#include "SASAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties()
	{
	}

	FGameplayEffectContextHandle effectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* sourceASC = nullptr;

	UPROPERTY()
	AController* sourceController = nullptr;

	UPROPERTY()
	ACharacter* sourceCharacter = nullptr;

	UPROPERTY()
	AActor* sourceAvatarActor = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* targetASC = nullptr;

	UPROPERTY()
	AController* targetController = nullptr;

	UPROPERTY()
	ACharacter* targetCharacter = nullptr;

	UPROPERTY()
	AActor* targetAvatarActor = nullptr;
};

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API USASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	USASAttributeSet();

	virtual void
	GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void
	PreAttributeChange(const FGameplayAttribute& attribute,
	                   float& newValue) override;

	virtual void
	PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category= "Vital Attributes")
	FGameplayAttributeData health;
	ATTRIBUTE_ACCESSORS(USASAttributeSet, health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category= "Vital Attributes")
	FGameplayAttributeData maxHealth;
	ATTRIBUTE_ACCESSORS(USASAttributeSet, maxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category= "Vital Attributes")
	FGameplayAttributeData mana;
	ATTRIBUTE_ACCESSORS(USASAttributeSet, mana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData maxMana;
	ATTRIBUTE_ACCESSORS(USASAttributeSet, maxMana)

	UFUNCTION()
	void
	OnRep_Health(const FGameplayAttributeData& oldHealth) const;

	UFUNCTION()
	void
	OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const;

	UFUNCTION()
	void
	OnRep_Mana(const FGameplayAttributeData& oldMana) const;

	UFUNCTION()
	void
	OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const;

private:
	static void
	SetEffectProperties(const struct FGameplayEffectModCallbackData& data,
	                    FEffectProperties& effectProperties);
};
