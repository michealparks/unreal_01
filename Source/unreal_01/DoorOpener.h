// Copyright Micheal Parks 2016

#pragma once

#include "Components/ActorComponent.h"
#include "DoorOpener.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_01_API UDoorOpener : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpener();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    void ToggleDoor(float Direction);

    UPROPERTY(EditAnywhere)
    float RotationDelta = 8.0f;
    
    UPROPERTY(VisibleAnywhere)
    float Yaw = -90.0f;
    
    UPROPERTY(EditAnywhere)
    float OpenAngle = 40.0f;
    
    UPROPERTY(EditAnywhere)
    float ClosedAngle = -90.0f;
    
    FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    AActor* Owner;

    APawn*  ActorThatOpens;
};
