// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentTrap.h"
#include "DestroyTrap.generated.h"

/**
 * 
 */
UCLASS()
class LESTATASK_API ADestroyTrap : public AParentTrap
{
	GENERATED_BODY()
	
private:

	virtual void TrapAction() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* IdleMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* WarningMaterial;

private:
	int TimerCount = 0;
	ADestroyTrap* Trap;
};
