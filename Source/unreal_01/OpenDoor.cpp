// Copyright Micheal Parks 2016

#include "unreal_01.h"
#include "OpenDoor.h"


// Sets default values
AOpenDoor::AOpenDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	FRotator NewRotation = FRotator(0.0f, 0.0f, 90.0f);
	Owner->SetActorRotation(NewRotation);
}

// Called every frame
void AOpenDoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	
}

