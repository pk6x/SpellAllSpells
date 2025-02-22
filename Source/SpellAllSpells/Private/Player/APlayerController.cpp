// Copyright me

#include "Player/APlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interaction/EnemyInterface.h"

AAPlayerController::AAPlayerController()
{
	bReplicates = true;
}

void AAPlayerController::PlayerTick(const float deltaTime)
{
	Super::PlayerTick(deltaTime);
}

void AAPlayerController::CursorTrace()
{
	FHitResult cursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, cursorHit);
	if (!cursorHit.bBlockingHit)
	{
		return;
	}

	lastActor = thisActor;
	thisActor = cursorHit.GetActor();

	/*
	 * Line trace from cursor. There are several scenarios:
	 * A. lastActor is null && thisActor is null
	 *    - Do nothing.
	 * B. lastActor is null && thisActor is valid
	 *    - Highlight thisActor
	 * C. lastActor is valid && thisActor is null
	 *    - Unhighlight lastActor
	 * D. Both actors are valid but lastActor != thisActor
	 *    - unhighlight lastActor, and highlight thisActor
	 * E. Both actors are valid, and are the same actor
	 *    - Do nothing
	 */

	if (lastActor == nullptr)
	{
		if (thisActor != nullptr)
		{
			thisActor->HighlightActor();
		}
		else
		{
			
		}
	}
	else
	{
		if (thisActor == nullptr)
		{
			lastActor->UnHighlightActor();
		}
		else
		{
			if (lastActor != thisActor)
			{
				lastActor->UnHighlightActor();
				thisActor->HighlightActor();
			}
			else
			{
				
			}
		}
	}

	#if 0
	if (thisActor != lastActor)
	{
		if (lastActor != nullptr)
		{
			lastActor->UnHighlightActor();
		}

		if (thisActor != nullptr)
		{
			thisActor->HighlightActor();
		}
	}
	#endif
}

void AAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(playerContext);

	UEnhancedInputLocalPlayerSubsystem* subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(subsystem);
	subsystem->AddMappingContext(playerContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;

	FInputModeGameAndUI inputModeData;
	inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	inputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(inputModeData);
}

void AAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* enhancedInputComponent =
			CastChecked<UEnhancedInputComponent>(InputComponent);

	enhancedInputComponent->BindAction(moveAction,
	                                   ETriggerEvent::Triggered,
	                                   this,
	                                   &AAPlayerController::Move);
}

void AAPlayerController::Move(const FInputActionValue& inputActionValue)
{
	const FVector2d inputAxisVector = inputActionValue.Get<FVector2d>();
	const FRotator rotation = GetControlRotation();
	const FRotator yawRotation(0.f, rotation.Yaw, 0.f);

	const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* controlledPawn = GetPawn<APawn>())
	{
		controlledPawn->AddMovementInput(forwardDirection, inputAxisVector.Y);
		controlledPawn->AddMovementInput(rightDirection, inputAxisVector.X);
	}
}
