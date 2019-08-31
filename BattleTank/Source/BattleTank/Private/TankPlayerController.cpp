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

    FVector HitLocation; // Out parameter
    if(GetSightRayHitLocation(HitLocation)) {  //Has a "side-effect" , is going to line-trace
        //UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"),*HitLocation.ToString());
        // TODO Tell controlled tank to aim at this point
    }
}

// Get world location of linetrace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
    //OutHitLocation = FVector(1.0);
    // Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX,ViewportSizeY);
    //UE_LOG(LogTemp, Warning, TEXT("ViewportSize: (%s)"),*FVector2D(ViewportSizeX,ViewportSizeY).ToString());
    //UE_LOG(LogTemp, Warning, TEXT("X,Y: (%s)"),*FVector2D(CrosshairXLocation,CrosshairYLocation).ToString());

    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    //UE_LOG(LogTemp, Warning, TEXT("CrosshairLocation: (%s)"),*ScreenLocation.ToString());

    // "de-project" the screen position of the crosshair to a world direction
    // Line-trace along that look direction, see what we hit (up to max range)

    return true;

}