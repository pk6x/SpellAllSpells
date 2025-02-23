// Copyright me


#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/ThePlayerState.h"

APlayerCharacter::
APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void APlayerCharacter::
PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);

	// Init ability actor info for the server
	InitAbilityAndAttributeActorInfo();
}

void APlayerCharacter::
OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityAndAttributeActorInfo();
}

void APlayerCharacter::
InitAbilityAndAttributeActorInfo()
{
	AThePlayerState* thePlayerState = GetPlayerState<AThePlayerState>();
	check(thePlayerState);
	thePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(thePlayerState, this);
	abilitySystemComponent = thePlayerState->GetAbilitySystemComponent();
	attributeSet = thePlayerState->GetAttributeSet();
}
