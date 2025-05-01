// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation(); // Fetch the starting location of the platform.
    TargetLocation = StartLocation + MoveOffset; // Setting the Target location to equal the start location + the movement offset.
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation(); // Get the current location of the platform
	FVector Direction = (TargetLocation - StartLocation).GetSafeNormal(); // Set the direction of the platform to the targetlocation - startlocation, using getsafenormal to negate divide by zero errors
	float JourneyLength = FVector::Dist(StartLocation, TargetLocation); // Get the journeys length by comparing the start location to the target location

	// Move the platform
	FVector NewLocation = CurrentLocation + Direction * MoveSpeed * DeltaTime; // Set the new location based on the current location + the direction and platforms move speed.
	SetActorLocation(NewLocation); // Append the new location to the actor object

	float TraveledDistance = FVector::Dist(StartLocation, NewLocation); // Calculate the traveled distance by comparing the start location to the new location calculated above

	// Check if the platform has reached or passed the target by comparing if the traveled distance is greater than the journey length
	if (TraveledDistance >= JourneyLength)
	{
		// set to target location to avoid overshooting platform distance
		SetActorLocation(TargetLocation);

		// Swap Start and Target variables for it to go in reverse
		FVector Temp = StartLocation;
		StartLocation = TargetLocation;
		TargetLocation = Temp;
	}

}

