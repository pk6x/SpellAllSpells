// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SASWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, newHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, newMaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, newMana);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, newMaxMana);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SPELLALLSPELLS_API UOverlayWidgetController : public USASWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature onHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature onMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnManaChangedSignature onManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxManaChangedSignature onMaxManaChanged;

protected:
	void HealthChanged(const FOnAttributeChangeData& data);
	void MaxHealthChanged(const FOnAttributeChangeData& data);
	void ManaChanged(const FOnAttributeChangeData& data);
	void MaxManaChanged(const FOnAttributeChangeData& data);
};
