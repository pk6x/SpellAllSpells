// Copyright me

#pragma once

#include <CoreMinimal.h>
#include "Character/PlayerCharacterBase.h"

#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API APlayerCharacter : public APlayerCharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void PossessedBy(AController* newController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityAndAttributeActorInfo();
};
