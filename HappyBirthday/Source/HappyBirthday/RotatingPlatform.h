// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class HAPPYBIRTHDAY_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();

	// Base mesh component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform | Mesh")
		class UStaticMeshComponent* Mesh;

	// Toggle on/off rotating
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform | PlatformProperties")
		bool bRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform | PlatformProperties")
		bool bReverse;

	// Rate at which mesh should rotate
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Platform | PlatformProperties")
		float RotationRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
