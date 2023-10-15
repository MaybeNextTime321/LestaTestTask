#include "ParentTrap.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, All, All);

AParentTrap::AParentTrap()
{

	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent->InitSphereRadius(200.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetRootComponent(CollisionComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshCompoent");
	SetRootComponent(StaticMeshComponent);
}

void AParentTrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	Actor = OtherActor;
	ActorInTrap = true;
	if (!StartTimerInBegin) 
	{
		TrapAction();
	}
	
}

void AParentTrap::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	ActorInTrap = false;
}

void AParentTrap::BeginPlay()
{
	Super::BeginPlay();

	if (StartTimerInBegin) 
	{
		TrapAction();
	}
}

void AParentTrap::TrapAction()
{
	UE_LOG(LogBasePickup, Display, TEXT("Trap Action Activating"));
}

void AParentTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



