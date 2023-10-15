#include "MovingTrap.h"

DEFINE_LOG_CATEGORY_STATIC(LogMovingTrap, All, All);


void AMovingTrap::TrapAction()
{
	MovingLeft = !MovingLeft;
	if (MovingLeft) 
	{
		StaticMeshComponent->SetMaterial(0,LeftMaterial);
	}
	else 
	{
		StaticMeshComponent->SetMaterial(0,RightMaterial);
	}
}

void AMovingTrap::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMovingTrap::TrapAction, TrapTimerRate, IsRepeatingTrap);
}

void AMovingTrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	GetWorldTimerManager().SetTimer(ActorMoveTimer, this, &AMovingTrap::MoveActor, ActorMoveTimerRate, true);
}

void AMovingTrap::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	GetWorldTimerManager().ClearTimer(ActorMoveTimer);
}

void AMovingTrap::MoveActor()
{
	if (!IsValid(Actor)) 
	{
		UE_LOG(LogMovingTrap, Warning, TEXT("Moving Actor is Invalid!!"));
		return;
	}

	FVector ChangeVector;

	ChangeVector = GetActorRightVector();
	
	if(MovingLeft) 
	{
		ChangeVector = ChangeVector * -1;
	}

	ChangeVector*= PushForce;

	Actor->SetActorLocation(Actor->GetActorLocation() + ChangeVector);
}
