// Fill out your copyright notice in the Description page of Project Settings.


#include "Componentes/ComponenteContador.h"

// Sets default values for this component's properties
UComponenteContador::UComponenteContador()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UComponenteContador::AumentarContador()
{
	if (CargasActuales < CargasMaximas)
	{
		CargasActuales++;
	}

	return CargasActuales >= CargasMaximas;
}

bool UComponenteContador::YaEstaCompleto()
{
	return CargasActuales >= CargasMaximas;
}


// Called when the game starts
void UComponenteContador::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponenteContador::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

