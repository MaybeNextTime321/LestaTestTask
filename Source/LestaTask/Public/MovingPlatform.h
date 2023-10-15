// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class LESTATASK_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


UPROPERTY(EditAnywhere, Category = "Mesh")
UStaticMeshComponent* StaticMeshComponent;

UPROPERTY(EditAnyWhere, Category = "Platform")
float ZAmplitude = 50.0f;

UPROPERTY(EditAnyWhere, Category = "Platform")
float YAmplitude = 50.0f;

UPROPERTY(EditAnyWhere, Category = "Platform")
float XAmplitude = 50.0f;

UPROPERTY(EditAnyWhere, Category = "Platform")
float Frequency= 50.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;
};
