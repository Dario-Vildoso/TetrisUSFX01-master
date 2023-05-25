// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"
#include "Board.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "InventoryCharacter.h"
#include "ActorPruebas.h"


ATetrisUSFX01GameModeBase::ATetrisUSFX01GameModeBase() {
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    //DefaultPawnClass = ABoard::StaticClass();
    DefaultPawnClass = AInventoryCharacter::StaticClass();

    siguientePosicionZ = 0;
}

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    // Call the parent class version of this function
    Super::BeginPlay();

    // Displays a red message on the screen for 10 seconds 
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));
    // Spawn an instance of the AMyFirstActor class at the 
    //default location.
    FTransform SpawnLocation;
    GetWorld()->SpawnActor<AActorPruebas>(AActorPruebas::StaticClass(), SpawnLocation);

    //FRotator Rotacion1(0.0, 0.0, 0.0);
    //FVector Ubicacion1(0.0, 5.0, 5.0);
    //SpawnedBlock1 = GetWorld()->SpawnActor<ABlock>(Ubicacion1, Rotacion1);
    //AdaptadorMovimientoAleatorio1 = NewObject<UAdaptadorMovimientoAleatorio_CA>(SpawnedBlock1);
    //AdaptadorMovimientoAleatorio1->RegisterComponent();

    //FRotator Rotacion2(0.0, 0.0, 0.0);
    //FVector Ubicacion2(0.0, -5.0, 5.0);
    //SpawnedBlock2 = GetWorld()->SpawnActor<ABlock>(Ubicacion2, Rotacion2);
    //AdaptadorMovimientoAleatorio2 = NewObject<UAdaptadorMovimientoAleatorio_CA>(SpawnedBlock2);
    //AdaptadorMovimientoAleatorio2->RegisterComponent();

    //FVector Ubicacion3(0.0, -140.0, 130.0);
    //FRotator Rotacion3(0.0, 0.0, 0.0);
    //EstructuraConcretaActual = GetWorld()->SpawnActor<AEstructuraConcreta>(Ubicacion3, Rotacion3);
    //EstructuraMultirotacionActual = GetWorld()->SpawnActor<AEstructuraMultirotacion>(AEstructuraMultirotacion::StaticClass());
    //EstructuraMultirotacionActual->SetEstructura(EstructuraConcretaActual);
    // Displays a red message on the screen for 10 seconds
    //GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Block"));
    // Spawn an instance of the AMyFirstActor class at the
    //default location.
    /*FTransform SpawnLocation;
    SpawnedActor = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), SpawnLocation);
    SpawnedActor->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/

    for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if (it->GetFName() == TEXT("BoardCamera"))
        //if (it->GetFName() == TEXT("LeftCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

}

// Called every frame
void ATetrisUSFX01GameModeBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   /* FTransform SpawnLocation;

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/ 

    //EstructuraConcretaActual->Rotar();
    //EstructuraMultirotacionActual->Rotar();
}


void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
	//if (SpawnedActor != nullptr)
 //  {
 //     // Displays a red message on the screen for 10 seconds
 //     GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
 //     SpawnedActor->Destroy();
 //  }
}
