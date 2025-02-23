// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

#include "SASWidgetController.generated.h"


/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API USASWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> playerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> playerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> attributeSet;
};
