#include "DestroyTrap.h"

void ADestroyTrap::TrapAction()
{
	switch (TimerCount)
	{
	case 0:
		
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADestroyTrap::TrapAction, TrapTimerRate, IsRepeatingTrap);
		StaticMeshComponent->SetMaterial(0,WarningMaterial);
		++TimerCount;
		break;
	case 1:
		StaticMeshComponent->SetVisibility(false);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADestroyTrap::TrapAction, TrapRespawnTime, IsRepeatingTrap);
		++TimerCount;
		break;
	case 2:
		StaticMeshComponent->SetVisibility(true);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		TimerCount = 0;
		StaticMeshComponent->SetMaterial(0,IdleMaterial);
		break;
	}
}

void ADestroyTrap::BeginPlay()
{
	Super::BeginPlay();

	Trap = this;
	StaticMeshComponent->SetMaterial(0,IdleMaterial);
}
