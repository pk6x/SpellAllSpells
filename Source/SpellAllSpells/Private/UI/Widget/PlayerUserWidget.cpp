// Copyight pk6x.


#include "UI/Widget/PlayerUserWidget.h"

void UPlayerUserWidget::SetWidgetController(UObject* inWidgetController)
{
	widgetController = inWidgetController;
	WidgetControllerSet();
}
