// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AcidRainBlock.generated.h"

UCLASS()
class ACIDRAIN_API AAcidRainBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAcidRainBlock();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform)override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Config")
	FString BlockText;

	int32 BlockSize;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USceneComponent* Root;

	UStaticMesh* CubeReference;

	TArray<UStaticMeshComponent*> TextBlocks;
private:
};
