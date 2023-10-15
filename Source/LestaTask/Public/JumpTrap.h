// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentTrap.h"
#include "JumpTrap.generated.h"

/**
 * 
 */
UCLASS()
class LESTATASK_API AJumpTrap : public AParentTrap
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditAnywhere, Category = "MovingTrap")
	float PushForce = 5.0f;


private:
	virtual void TrapAction();
	
};
