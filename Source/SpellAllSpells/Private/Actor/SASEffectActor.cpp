// Copyight pk6x.


#include "Actor/SASEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SASAttributeSet.h"

ASASEffectActor::
ASASEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(mesh);

	sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	sphere->SetupAttachment(GetRootComponent());
}

void ASASEffectActor::
OnOverlap(UPrimitiveComponent* overlappedComponent,
          AActor* otherActor,
          UPrimitiveComponent* otherComp,
          int32 otherBodyIndex,
          bool bFromSweep,
          const FHitResult& sweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* aSCInterface =
		Cast<IAbilitySystemInterface>(otherActor))
	{
		const USASAttributeSet* sasAttributeSet = 
		Cast<USASAttributeSet>
		(aSCInterface->GetAbilitySystemComponent()->GetAttributeSet(USASAttributeSet::StaticClass()));

		USASAttributeSet* mutableSASAttributeSet = const_cast<USASAttributeSet*>(sasAttributeSet);
		mutableSASAttributeSet->Sethealth(sasAttributeSet->Gethealth() + 25.f);
		Destroy();
	}
}

void ASASEffectActor::
EndOverlap(UPrimitiveComponent* overlappedComponent,
           AActor* otherActor,
           UPrimitiveComponent* otherComp,
           int32 otherBodyIndex)
{
}

void ASASEffectActor::
BeginPlay()
{
	Super::BeginPlay();

	sphere->OnComponentBeginOverlap.AddDynamic(this, &ASASEffectActor::OnOverlap);
	sphere->OnComponentEndOverlap.AddDynamic(this, &ASASEffectActor::EndOverlap);
}
