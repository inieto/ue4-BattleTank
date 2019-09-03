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
// Editor Properties
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = 1.0f/2; //Little hacky, should read from BP properties

    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 1.0f/3; //Little hacky, should read from BP properties

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 10.f * 100 * 1000; //10km = 10cm * 100 (to m) * 1000 (to km);

// Members
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;

};