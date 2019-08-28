#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
    ATank* GetPlayerTank() const;  //"it's const because it's not going to change anything"

public:
    ATank* GetControlledTank() const;
    void BeginPlay() override;
};
