// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpTrap.h"
#include "GameFramework/CharacterMovementComponent.h"

void AJumpTrap::TrapAction()
{
	if (!IsValid(Actor)) 
	{
		return;
	}
	UCharacterMovementComponent* MoveComponent =  Actor->FindComponentByClass<UCharacterMovementComponent>();

	if (MoveComponent) 
	{
		FVector LaunchVelocity = FVector(0, 0, PushForce);
		MoveComponent->Launch(LaunchVelocity);
	}
}
