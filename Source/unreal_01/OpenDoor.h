// Copyright Micheal Parks 2016

#pragma once

#include "GameFramework/Actor.h"
#include "OpenDoor.generated.h"

UCLASS()
class UNREAL_01_API AOpenDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOpenDoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
