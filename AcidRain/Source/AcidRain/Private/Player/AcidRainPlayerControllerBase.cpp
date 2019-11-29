// Fill out your copyright notice in the Description page of Project Settings.


#include "AcidRainPlayerControllerBase.h"
#include "..\..\Public\Player\AcidRainPlayerControllerBase.h"

AAcidRainPlayerControllerBase::AAcidRainPlayerControllerBase()
{
}

void AAcidRainPlayerControllerBase::BeginPlay()
{
	if (PlayerCameraManager)
	{
		PlayerCameraManager->bIsOrthographic = true;
	}
}
