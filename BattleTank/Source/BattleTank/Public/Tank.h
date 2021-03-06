#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"      //Put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

protected:
    UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Sets default values for this pawn's properties
    ATank();
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
