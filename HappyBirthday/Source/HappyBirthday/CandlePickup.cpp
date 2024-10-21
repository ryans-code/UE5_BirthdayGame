// Fill out your copyright notice in the Description page of Project Settings.


#include "CandlePickup.h"
#include "MainCharacter.h"

ACandlePickup::ACandlePickup()
{
	CandleIncreaseAmount = 1;
}

void ACandlePickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("ACandlePickup::OnOverlapBegin"));

	AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
	if (MainCharacter) {
		MainCharacter->SetCandleCount(CandleIncreaseAmount);
	}

	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
