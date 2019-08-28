#include "TankPlayerController.h"
#include "BattleTank.h"

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

ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank> (GetPawn());
}