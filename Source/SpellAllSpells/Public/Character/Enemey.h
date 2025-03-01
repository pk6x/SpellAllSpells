// Copyright me

#pragma once

#include <CoreMinimal.h>
#include "Interaction/EnemyInterface.h"
#include "Character/PlayerCharacterBase.h"

#include "Enemey.generated.h"

/**
 * 
 */
UCLASS()
class SPELLALLSPELLS_API AEnemey : public APlayerCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemey();

	/* Enemey Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* end of Enemy Interface*/

protected:
	virtual void BeginPlay() override;
};
