// Copyight pk6x.


#include "Actor/SASEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

ASASEffectActor::
ASASEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void ASASEffectActor::
BeginPlay()
{
	Super::BeginPlay();
}

void ASASEffectActor::
ApplyEffectToTarget(AActor* targetActor,
                    TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	UAbilitySystemComponent* targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
	if (targetASC == nullptr)
	{
		return;
	}

	check(gameplayEffectClass);

	FGameplayEffectContextHandle effectContextHandle = targetASC->MakeEffectContext();
	effectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle effectSpecHandle = targetASC->MakeOutgoingSpec(gameplayEffectClass,
	                                                                         1.f,
	                                                                         effectContextHandle);

	targetASC->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());
}
