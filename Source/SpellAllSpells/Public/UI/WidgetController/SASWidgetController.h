// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/SASAttributeSet.h"
#include "UObject/Object.h"

#include "SASWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams()
	{
	}

	FWidgetControllerParams(APlayerController* pc,
	                        APlayerState* ps,
	                        UAbilitySystemComponent* asc,
	                        UAttributeSet* as)
		: playerController(pc),
		  playerState(ps),
		  abilitySystemComponent(asc),
		  attributeSet(as)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> playerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> playerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> attributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API USASWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams wcParams);

	virtual void BroadcastInitialValues();

	virtual void BindCallbacksToDependencies(); 

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
