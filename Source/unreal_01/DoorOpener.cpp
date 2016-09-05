// Copyright Micheal Parks 2016

#include "unreal_01.h"
#include "DoorOpener.h"

#include <cmath>


// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = GetOwner();
}


// Called every frame
void UDoorOpener::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	NewRotation.Yaw += RotationSign;

	if (std::abs(NewRotation.Yaw) > 90.0f) {
		RotationSign *= -1.0f;
	}

	Owner->SetActorRotation(NewRotation);
	// ...
}

