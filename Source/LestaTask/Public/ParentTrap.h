// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentTrap.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class StaticMesh;

UCLASS()
class LESTATASK_API AParentTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParentTrap();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(VisibleAnywhere, Category = "Trap")
	USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, Category = "Trap")
	UStaticMeshComponent* StaticMeshComponent;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void BeginPlay() override;

	bool ActorInTrap = false;

	UPROPERTY(EditDefaultsOnly, Category = "Trap")
	bool StartTimerInBegin = false;

	UPROPERTY(EditDefaultsOnly, Category = "Trap")
	bool IsRepeatingTrap = false;

	UPROPERTY(EditDefaultsOnly, Category = "Trap")
	float TrapTimerRate = 1;


	UPROPERTY(EditDefaultsOnly, Category = "Trap")
	float TrapRespawnTime = 1;

	FTimerHandle TimerHandle;

	virtual void TrapAction();

protected:
	AActor* Actor;


public:	
	virtual void Tick(float DeltaTime) override;

};
