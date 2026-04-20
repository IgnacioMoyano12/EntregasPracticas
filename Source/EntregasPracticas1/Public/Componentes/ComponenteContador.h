// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponenteContador.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENTREGASPRACTICAS1_API UComponenteContador : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponenteContador();

	UFUNCTION(BlueprintCallable)
	bool AumentarContador();

	UFUNCTION(BlueprintCallable)
	bool YaEstaCompleto();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CargasActuales = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CargasMaximas = 1;
};
