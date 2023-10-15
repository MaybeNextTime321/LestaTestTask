#include "HealthComponent.h"
DEFINE_LOG_CATEGORY_STATIC(HealthComponent, All, All);

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UHealthComponent::GetHealthPersent() const
{
	if (Health == 0) 
	{
		return 0;
	}
	else 
	{
		return Health / DefaultHealth;
	}

}

void UHealthComponent::SetDamage(float DamageAmount)
{
	UE_LOG(HealthComponent, Display, TEXT("TAKE DAMAGE, %f"),DamageAmount);
	Health -= DamageAmount;
	Health = (Health < 0) ? 0 : Health;
	if (FMath::IsNearlyZero(Health)) 
	{
		GetOwner()->Destroy();
	}
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
}


void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

