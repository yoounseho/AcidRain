// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AcidRainPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ACIDRAIN_API AAcidRainPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

		AAcidRainPlayerControllerBase();
	
public:
	virtual void BeginPlay()override;
};
