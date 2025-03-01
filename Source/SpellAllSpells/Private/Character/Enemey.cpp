// Copyright me

#include "Character/Enemey.h"

#include "AbilitySystem/SASAbilitySystemComponent.h"
#include "AbilitySystem/SASAttributeSet.h"
#include "SpellAllSpells/SpellAllSpells.h"

AEnemey::
AEnemey()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(this);

	abilitySystemComponent =
		CreateDefaultSubobject<USASAbilitySystemComponent>("AbilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	attributeSet = CreateDefaultSubobject<USASAttributeSet>("AttributeSet");
}

void AEnemey::
HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	weapon->SetRenderCustomDepth(true);
	weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemey::
UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);

	weapon->SetRenderCustomDepth(false);
}

void AEnemey::
BeginPlay()
{
	Super::BeginPlay();

	abilitySystemComponent->InitAbilityActorInfo(this, this);
}
