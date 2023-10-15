#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshCompoent");
	SetRootComponent(StaticMeshComponent);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float time = GetWorld()->GetTimeSeconds();

	CurrentLocation.Z = InitialLocation.Z + ZAmplitude * FMath::Sin(Frequency * time);
	CurrentLocation.Y = InitialLocation.Y + YAmplitude * FMath::Sin(Frequency * time);
	CurrentLocation.X = InitialLocation.X + XAmplitude * FMath::Sin(Frequency * time);
	SetActorLocation(CurrentLocation);
}

