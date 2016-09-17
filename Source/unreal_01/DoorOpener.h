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
    float RotationDelta = 4.0f;
    
    UPROPERTY(VisibleAnywhere)
    float Yaw = -90.0f;
    
    UPROPERTY(EditAnywhere)
    float OpenAngle = 40.0f;
    
    UPROPERTY(EditAnywhere)
    float ClosedAngle = -90.0f;

	UPROPERTY(EditAnywhere)
	float UnlockPeriod = 60.0f;

	float CurrentTime;
	float UnlockedTime;

	UPROPERTY(EditAnywhere)
	bool IsDoorUnlocked = false;
    
    FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* DoorUnlockTrigger;
    
	UWorld* World;
    AActor* Owner;

    APawn* ActorThatOpens;
};
