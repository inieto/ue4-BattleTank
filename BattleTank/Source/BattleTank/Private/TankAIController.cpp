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

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //TODO Move towards the player

    //Aim towards the player
    AimTowardsPlayerController();

    //Fire if ready
}

// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
void ATankAIController::AimTowardsPlayerController() {  //it's not const since it will change state on the Tank
    auto PlayerTank = GetPlayerTank();
    auto ControlledTank = GetControlledTank();
    if(!PlayerTank || !ControlledTank) return;
    ControlledTank->AimAt(PlayerTank->GetActorLocation());
}