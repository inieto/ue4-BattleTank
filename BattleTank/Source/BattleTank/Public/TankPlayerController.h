#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  //Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;    //virtual allows this method to be overwritten by a child
    //override says to the compiler that the parent of this class must have the same method we are overriding here

    ATank* GetControlledTank() const;
	void BeginPlay() override;
private:
    void AimTowardsCrosshair();
};
