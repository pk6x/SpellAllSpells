// Copyight pk6x.

#include "UI/WidgetController/SASWidgetController.h"

void USASWidgetController::
SetWidgetControllerParams(const FWidgetControllerParams wcParams)
{
	playerController = wcParams.playerController;
	playerState = wcParams.playerState;
	abilitySystemComponent = wcParams.abilitySystemComponent;
	attributeSet = wcParams.attributeSet;
}

void USASWidgetController::
BroadcastInitialValues()
{
}

void USASWidgetController::
BindCallbacksToDependencies()
{
}
