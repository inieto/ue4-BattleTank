#include "TankAIController.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();
    //UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

    auto PlayerTank = GetPlayerTank();
    if(!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
    }
}

ATank* ATankAIController::GetControlledTank() const {
    return Cast<ATank> (GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    return Cast<ATank> (PlayerPawn);
}