#pragma once

#include "CoreMinimal.h"
#include "ParentTrap.h"
#include "MovingTrap.generated.h"

/**
 * 
 */
UCLASS()
class LESTATASK_API AMovingTrap : public AParentTrap
{
	GENERATED_BODY()
	

protected:
	virtual void TrapAction() override;
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* LeftMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UMaterialInstance* RightMaterial;

	UPROPERTY(EditAnywhere, Category = "MovingTrap")
	bool IsRandomMove = false;

	UPROPERTY(EditAnywhere, Category = "MovingTrap")
	float ActorMoveTimerRate = 0.3;

	UPROPERTY(EditAnywhere, Category = "MovingTrap")
	float PushForce = 5.0f;

private:
	void MoveActor();
	bool MovingLeft = true;
	FTimerHandle ActorMoveTimer;
};
