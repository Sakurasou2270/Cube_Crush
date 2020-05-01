// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"

class UBoxComponent;
class AFPSCharacter;

UCLASS()
class TEST_API ALaunchPad : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ALaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent *BoxComp;

	AFPSCharacter *Player;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent *OverlappedComp,
		AActor *OtherActor,
		UPrimitiveComponent *OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);
};
