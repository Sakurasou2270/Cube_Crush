// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

AMainGameMode::AMainGameMode()
{
}

void AMainGameMode::BeginPlay()
{
    Super::BeginPlay();
}

void AMainGameMode::EndGame(APawn *InstigatorPawn)
{
    if (InstigatorPawn)
    {
        // Disabling Input
        InstigatorPawn->DisableInput(nullptr);
        // Getting all actors in world
        TArray<AActor *> ReturnedActors;

        // Getting all actors in SpectatingScreen class and returning them
        UGameplayStatics::GetAllActorsOfClass(this, SpectatingScreen, ReturnedActors);
        // Getting the player controller
        APlayerController *PC = Cast<APlayerController>(InstigatorPawn->GetController());

        // Iterating over ReturnedActors
        if (ReturnedActors.Num() > 0)
        {
            AActor *NewTargetLocation = ReturnedActors[0];

            if (PC)
            {
                PC->SetViewTargetWithBlend(NewTargetLocation, 2.f, VTBlend_Cubic, 0.f, false);
            }
        }
    }
}