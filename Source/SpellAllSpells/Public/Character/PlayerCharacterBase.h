// Copyright me

#pragma once

#include <CoreMinimal.h>

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"

#include "PlayerCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class SPELLALLSPELLS_API APlayerCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APlayerCharacterBase();

	virtual UAbilitySystemComponent*
	GetAbilitySystemComponent() const override;

	UAttributeSet*
	GetAttributeSet() const { return attributeSet; }

protected:
	virtual void
	BeginPlay() override;

	virtual void
	InitAbilityAndAttributeActorInfo();

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;
};
