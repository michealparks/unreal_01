// Copyright Micheal Parks 2016

#include "unreal_01.h"
#include "DoorOpener.h"

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
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UDoorOpener::ToggleDoor(float Direction)
{
    Yaw += (RotationDelta * Direction);
    
    NewRotation.Yaw = Yaw;
    
    Owner->SetActorRotation(NewRotation);
}

// Called every frame
void UDoorOpener::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
    
    if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
        if (Yaw < OpenAngle) ToggleDoor(1.0f);
    } else {
        if (Yaw > ClosedAngle) ToggleDoor(-1.0f);
    }
}

