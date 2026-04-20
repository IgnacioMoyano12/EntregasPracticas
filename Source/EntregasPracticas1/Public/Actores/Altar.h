// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Altar.generated.h"


class UBoxComponent;
class UComponenteContador;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FContadorDeAltares, int, Altares);

UCLASS()
class ENTREGASPRACTICAS1_API AAltar : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAltar();
	UFUNCTION(BlueprintCallable)
	void TimerAltar();

	UPROPERTY(BlueprintAssignable)
	FContadorDeAltares ContadordeAltares;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void Interact_Implementation(AActor* Actor) override;
	UPROPERTY()
	FTimerHandle TimerDelAltar;

private: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshAltar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UComponenteContador> ComponenteDeCarga;
};
