// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"

#include "SASEffectActor.generated.h"

UCLASS()
class SPELLALLSPELLS_API ASASEffectActor : public AActor
{
	GENERATED_BODY()

public:
	ASASEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* targetActor,
	                         TSubclassOf<UGameplayEffect> gameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> instantGameplayEffectClass;

};
