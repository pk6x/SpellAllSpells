// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/SASWidgetController.h"
#include "SASHUD.generated.h"

struct FWidgetControllerParams;
class UOverlayWidgetController;
class UPlayerUserWidget;

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API ASASHUD : public AHUD
{
	GENERATED_BODY()

public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& wcParams);

	void InitOverlay(APlayerController* pc,
	                 APlayerState* ps,
	                 UAbilitySystemComponent* asc,
	                 UAttributeSet* as);

	UPROPERTY()
	TObjectPtr<UPlayerUserWidget> overlayWidget;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerUserWidget> overlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> overlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> overlayWidgetControllerClass;
};
