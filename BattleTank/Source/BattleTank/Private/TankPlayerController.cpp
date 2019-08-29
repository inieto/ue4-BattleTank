#include "TankPlayerController.h"
#include "BattleTank.h"

//Order of things: 1st BeginPlay, 2nd Tick and then all other methods.

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

    auto ControlledTank = GetControlledTank();
    if(!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
    }
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
    //UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank> (GetPawn());
}

// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
void ATankPlayerController::AimTowardsCrosshair() {  //it's not const since it will change state on the Tank
    if(!GetControlledTank()) return;

    // Get world location through crosshair (if linetrace)
    // If it hits the landscape
        // Tell controlled tank to aim at this point
}