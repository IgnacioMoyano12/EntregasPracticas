// Fill out your copyright notice in the Description page of Project Settings.


#include "Actores/Altar.h"
#include "Componentes/ComponenteContador.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAltar::AAltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ComponenteDeCarga = CreateDefaultSubobject<UComponenteContador>("ComponenteContador");
    BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    RootComponent = BoxCollision;
    BoxCollision->SetLineThickness(5);
    BoxCollision->SetBoxExtent(FVector(150, 150, 150));
    BoxCollision->SetHiddenInGame(false);


    MeshAltar = CreateDefaultSubobject<UStaticMeshComponent>("MeshAltar");
    MeshAltar->SetupAttachment(RootComponent);

}

void AAltar::TimerAltar()
{
    bool bAltarLleno= ComponenteDeCarga->AumentarContador();
    if (bAltarLleno)
    {
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "AltarLleno");
        //Se dispara el DELEGATE
        ContadordeAltares.Broadcast(ComponenteDeCarga->CargasActuales);
    }
    else
    {
        //En caso de que no esten las 3 cargas, se avisa
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "Carga anadida. Faltan mas...");
    }
}

// Called when the game starts or when spawned
void AAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAltar::Interact_Implementation(AActor* Actor)
{
    if (ComponenteDeCarga->YaEstaCompleto())
    {
        return;
    }
    if (GetWorldTimerManager().IsTimerActive(TimerDelAltar))
    {
        return;
    }
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, "Cargando altar...");
    GetWorldTimerManager().SetTimer(TimerDelAltar, this, &AAltar::TimerAltar, 2.0f, false);
}
