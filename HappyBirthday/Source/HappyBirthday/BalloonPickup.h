// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "BalloonPickup.generated.h"

/**
 * 
 */
UCLASS()
class HAPPYBIRTHDAY_API ABalloonPickup : public AItem
{
	GENERATED_BODY()

public:

	ABalloonPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int32 BalloonIncreaseAmount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
