// Copyright me

#include "Character/PlayerCharacterBase.h"

APlayerCharacterBase::
APlayerCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(this);
}

UAbilitySystemComponent* APlayerCharacterBase::
GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}

void APlayerCharacterBase::
BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacterBase::
InitAbilityAndAttributeActorInfo()
{
}
