// Fill out your copyright notice in the Description page of Project Settings.


#include "AcidRainBlock.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AAcidRainBlock::AAcidRainBlock()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeObj(TEXT("/Engine/BasicShapes/Cube"));
	CubeReference = CubeObj.Object;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAcidRainBlock::BeginPlay()
{
	Super::BeginPlay();
}

void AAcidRainBlock::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

	//�ڽ�ũ�ⱸ�ϱ�
	BlockSize = BlockText.Len();
	FVector CubeOrigin;
	FVector CubeExtent;
	if(CubeReference)
	{
		FBox CubeBound = CubeReference->GetBoundingBox(); 
		CubeOrigin = CubeBound.GetCenter();
		CubeExtent = CubeBound.GetExtent();
	}
	//�ڽ�����
	for (int i = 0; i < BlockSize; i++)
	{
		FString BlockMeshName = TEXT("Block");
		BlockMeshName.Append(FString::FromInt(i));
		UStaticMeshComponent* MeshComp = NewObject<UStaticMeshComponent>(this,UStaticMeshComponent::StaticClass(),*BlockMeshName);
		if (MeshComp)
		{
			if (CubeReference)
				MeshComp->SetStaticMesh(CubeReference);
			TextBlocks.Emplace(MeshComp);
			MeshComp->SetupAttachment(RootComponent);
			if (BlockSize % 2 == 1)
			{
				//ť��ݻ����� �߰�
				FVector AdditionalCubeRelativeLocation = FVector(CubeExtent.X,0,0);
				//((int32)(BlockSize / 2) - i) * CubeExtent.X * 2, 0, 0)�� ���� ť����ġ
				MeshComp->SetRelativeLocation(FVector(((int32)(BlockSize / 2) - i) * CubeExtent.X * 2, 0, 0) + AdditionalCubeRelativeLocation, false, nullptr, ETeleportType::TeleportPhysics);
			}
			else
			{
				//((int32)(BlockSize / 2) - i) * CubeExtent.X * 2, 0, 0)�� ���� ť����ġ
				MeshComp->SetRelativeLocation(FVector(((int32)(BlockSize / 2) - i) * CubeExtent.X * 2, 0, 0), false, nullptr, ETeleportType::TeleportPhysics);
			}
		}
	}
}

// Called every frame
void AAcidRainBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

