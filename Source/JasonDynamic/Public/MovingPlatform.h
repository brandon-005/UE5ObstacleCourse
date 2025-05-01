#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class JASONDYNAMIC_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    FVector StartLocation; // Defining StartLocation Variable
    FVector TargetLocation; // Defining TargetLocation Variable

    UPROPERTY(EditAnywhere, Category = "Platform Movement") // Creating a new property in the details panel for platform movement
    FVector MoveOffset = FVector(100.f, 0.f, 0.f); // Setting some default parameters

    UPROPERTY(EditAnywhere, Category = "Platform Movement") // Creating another property in the details panel for platform movement
    float MoveSpeed = 100.f; // Settting the default movement speed

    bool bMovingForward = true; // Boolean variable for if the platform is moving forwards or backwards, forward by default
};