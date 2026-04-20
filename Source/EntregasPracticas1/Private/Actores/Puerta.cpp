// Fill out your copyright notice in the Description page of Project Settings.


#include "Actores/Puerta.h"
#include "Actores/Altar.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    RootComponent = BoxCollision;
    BoxCollision->SetLineThickness(5);
    BoxCollision->SetBoxExtent(FVector(150, 150, 150));
    BoxCollision->SetHiddenInGame(false);


    MeshDoor = CreateDefaultSubobject<UStaticMeshComponent>("MeshAltar");
    MeshDoor->SetupAttachment(RootComponent);

}

void APuerta::AltarPrendido(int CantidaddeAltares)
{
    AltaresCompletados += 1;

    //Si el numero de altares completados es igual o mayor a la cantidad de altares en el array, se destruye la puerta
    if (AltaresCompletados == ListaDeAltares.Num())
    {
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, "LOS 3 ALTARES SE COMPLETARON - PUERTA DESTRUIDA");

        Destroy();
    }
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
    Super::BeginPlay();
    for (AAltar* AltarEnElMundo : ListaDeAltares)
    {
        if (AltarEnElMundo)
        {
            AltarEnElMundo->ContadordeAltares.AddDynamic(this, &APuerta::AltarPrendido);

    }
}
}

// Called every frame
void APuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

