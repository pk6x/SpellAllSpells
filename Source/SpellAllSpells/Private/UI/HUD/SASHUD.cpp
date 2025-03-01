// Copyight pk6x.


#include "UI/HUD/SASHUD.h"

#include "UI/Widget/PlayerUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ASASHUD::
GetOverlayWidgetController(const FWidgetControllerParams& wcParams)
{
	if (overlayWidgetController == nullptr)
	{
		overlayWidgetController = NewObject<UOverlayWidgetController>(this, overlayWidgetControllerClass);
		overlayWidgetController->SetWidgetControllerParams(wcParams);
		overlayWidgetController->BindCallbacksToDependencies();

		return (overlayWidgetController);
	}
	return (overlayWidgetController);
}

void ASASHUD::
InitOverlay(APlayerController* pc,
            APlayerState* ps,
            UAbilitySystemComponent* asc,
            UAttributeSet* as)
{
	checkf(overlayWidgetClass,
	       TEXT("Overlay Widget Class uninitialized, please fill out BP_SASHUD"))
	checkf(overlayWidgetControllerClass,
	       TEXT("Overlay Widget Controller Class uninitalized, please fill out BP_SASHUD"))

	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), overlayWidgetClass);
	
	overlayWidget = Cast<UPlayerUserWidget>(widget);

	const FWidgetControllerParams widgetControllerParams(pc, ps, asc, as);

	UOverlayWidgetController* widgetController;
	widgetController = GetOverlayWidgetController(widgetControllerParams);

	overlayWidget->SetWidgetController(widgetController);

	widgetController->BroadcastInitialValues();

	widget->AddToViewport();
}
