// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "CandlePickup.generated.h"

/**
 * 
 */
UCLASS()
class HAPPYBIRTHDAY_API ACandlePickup : public AItem
{
	GENERATED_BODY()
	
public:

	ACandlePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int32 CandleIncreaseAmount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
