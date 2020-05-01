// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemy::AEnemy()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxComp->InitBoxExtent(FVector(100.f, 100.f, 75.f));
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = BoxComp;

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapAttack);

	Enemy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Enemy->SetupAttachment(RootComponent);

	Damage = 25.f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100.f, 100.f, 75.f), FColor::Green, true, 0.f, 0, 5.f);

	Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (Player == nullptr || !Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Please Select A Targeting Pawn For %s"), *GetOwner()->GetName());
	}
}

void AEnemy::OnOverlapAttack(
	UPrimitiveComponent *OverlappedComp,
	AActor *OtherActor,
	UPrimitiveComponent *OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (Player->PlayerHealth >= 0)
	{
		Player->PlayerHealth -= Damage;
	}
	
	if (Player->PlayerHealth <= 0)
	{
		Player->PlayerDeath();
	}
	UE_LOG(LogTemp, Warning, TEXT("%f"), Player->GetPlayerHealth());
}