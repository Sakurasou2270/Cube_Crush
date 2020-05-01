// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class AFPSCharacter;

UCLASS()
class TEST_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Enemy")
	UBoxComponent *BoxComp;

	UPROPERTY(EditDefaultsOnly, Category = "Enemy")
	UStaticMeshComponent *Enemy;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	AFPSCharacter *Player = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	float Damage;

	UFUNCTION()
	void OnOverlapAttack(
		UPrimitiveComponent *OverlappedComp,
		AActor *OtherActor,
		UPrimitiveComponent *OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);
};
