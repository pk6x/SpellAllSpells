// Copyight pk6x.


#include "UI/WidgetController/OverlayWidgetController.h"

void UOverlayWidgetController::
BroadcastInitialValues()
{
	const USASAttributeSet* sasAttributeSet = CastChecked<USASAttributeSet>(attributeSet);

	onHealthChanged.Broadcast(sasAttributeSet->Gethealth());
	onMaxHealthChanged.Broadcast(sasAttributeSet->GetmaxHealth());
	onManaChanged.Broadcast(sasAttributeSet->Getmana());
	onMaxManaChanged.Broadcast(sasAttributeSet->GetmaxMana());
}

void UOverlayWidgetController::
BindCallbacksToDependencies()
{
	const USASAttributeSet* sasAttributeSet;
	sasAttributeSet = CastChecked<USASAttributeSet>(attributeSet);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		sasAttributeSet->GethealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		sasAttributeSet->GetmaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		sasAttributeSet->GetmanaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		sasAttributeSet->GetmaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::
HealthChanged(const FOnAttributeChangeData& data)
{
	onHealthChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::
MaxHealthChanged(const FOnAttributeChangeData& data)
{
	onMaxHealthChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& data)
{
	onManaChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& data)
{
	onMaxManaChanged.Broadcast(data.NewValue);
}
