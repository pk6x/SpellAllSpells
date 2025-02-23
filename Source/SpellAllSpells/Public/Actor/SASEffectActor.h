// Copyight pk6x.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"

#include "SASEffectActor.generated.h"

UCLASS()
class SPELLALLSPELLS_API ASASEffectActor : public AActor
{
	GENERATED_BODY()

public:
	ASASEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* overlappedComponent,
	                       AActor* otherActor,
	                       UPrimitiveComponent* otherComp,
	                       int32 otherBodyIndex,
	                       bool bFromSweep,
	                       const FHitResult& sweepResult);

	virtual void EndOverlap(UPrimitiveComponent* overlappedComponent,
	                        AActor* otherActor,
	                        UPrimitiveComponent* otherComp,
	                        int32 otherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh;
};
