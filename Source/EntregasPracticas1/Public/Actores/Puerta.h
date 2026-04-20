// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Altar.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "Puerta.generated.h"

UCLASS()
class ENTREGASPRACTICAS1_API APuerta : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuerta();

	UFUNCTION()
	void AltarPrendido(int CantidaddeAltares);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuracion")
	TArray<AAltar*> ListaDeAltares;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshDoor;

	int AltaresCompletados = 0;

};
