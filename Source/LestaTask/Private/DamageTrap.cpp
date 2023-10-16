#include "DamageTrap.h"
#include "HealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogDamageTrap, All, All);

void ADamageTrap::TrapAction()
{

	switch (TimerCount)
	{
		case 0:
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ADamageTrap::TrapAction, TrapTimerRate, IsRepeatingTrap);
			StaticMeshComponent->SetMaterial(0, WarningMaterial);
			++TimerCount;
			break;
		case 1:
			if (!TrapIsReloading)
			{
				TrapIsReloading = true;
				if (ActorInTrap)
				{
					MakeDamage();
				}
				StaticMeshComponent->SetMaterial(0, DamageMaterial);
				GetWorldTimerManager().SetTimer(TimerHandle, this, &ADamageTrap::ReloadTrap, TrapRespawnTime, IsRepeatingTrap);
				++TimerCount;
				break;
			}

	}

}

void ADamageTrap::BeginPlay()
{
	Super::BeginPlay();


	if (!IsValid(IdleMaterial)) 
	{
		UE_LOG(LogDamageTrap, Warning, TEXT("Idle Mesh invalid!!!"));
		return;
	}

	StaticMeshComponent->SetMaterial(0,IdleMaterial);

}

void ADamageTrap::MakeDamage()
{
	UHealthComponent* Health = Actor->GetComponentByClass<UHealthComponent>();

	if (IsValid(Health)) 
	{
		Health->SetDamage(DamageAmount);
	}
	else 
	{
		UE_LOG(LogDamageTrap, Warning, TEXT("Health component Invalid!!"));
	}
}

void ADamageTrap::ReloadTrap()
{
	TimerCount = 0;
	StaticMeshComponent->SetMaterial(0, IdleMaterial);
	if (ActorInTrap)
	{
		TrapAction();
	}
	TrapIsReloading = false;
}
