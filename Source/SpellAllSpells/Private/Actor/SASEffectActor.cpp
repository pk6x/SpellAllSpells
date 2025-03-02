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

void
ASASEffectActor::
BeginPlay()
{
	Super::BeginPlay();
}

void
ASASEffectActor::
ApplyEffectToTarget(AActor* targetActor,
                    const TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	UAbilitySystemComponent* targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
	if (targetASC == nullptr)
	{
		return;
	}

	check(gameplayEffectClass);

	FGameplayEffectContextHandle effectContextHandle = targetASC->MakeEffectContext();
	effectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle effectSpecHandle = targetASC->MakeOutgoingSpec(gameplayEffectClass,
			 actorLevel,
			 effectContextHandle);

	const FActiveGameplayEffectHandle activeEffectHandle =
			targetASC->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());

	const bool bIsInfinite =
			effectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;

	if (bIsInfinite && infinteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		activeEffectHandles.Add(activeEffectHandle, targetASC);
	}
}

void
ASASEffectActor::
OnOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, instantGameplayEffectClass);
	}

	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, durationGameplayEffectClass);
	}

	if (infiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, infiniteGameplayEffectClass);
	}
}

void
ASASEffectActor::
OnEndOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, instantGameplayEffectClass);
	}

	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, durationGameplayEffectClass);
	}

	if (infiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, infiniteGameplayEffectClass);
	}

	if (infinteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
		if (!IsValid(targetASC))
		{
			return;
		}

		TArray<FActiveGameplayEffectHandle> handlesToRemove;

		for (auto handlePair : activeEffectHandles)
		{
			if (targetASC == handlePair.Value)
			{
				targetASC->RemoveActiveGameplayEffect(handlePair.Key, 1);
				handlesToRemove.Add(handlePair.Key);
			}
		}

		for (auto& handle : handlesToRemove)
		{
			activeEffectHandles.FindAndRemoveChecked(handle);
		}
	}
}
