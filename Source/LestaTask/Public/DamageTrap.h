// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentTrap.h"
#include "DamageTrap.generated.h"

/**
 * 
 */
UCLASS()
class LESTATASK_API ADamageTrap : public AParentTrap
{
	GENERATED_BODY()
	
protected:
	virtual void TrapAction() override;
	virtual void BeginPlay() override;

	UStaticMesh* CurrentMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	float DamageAmount = 50.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* IdleMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* WarningMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* DamageMaterial;
private:
	int TimerCount = 0;
	void MakeDamage();
};
