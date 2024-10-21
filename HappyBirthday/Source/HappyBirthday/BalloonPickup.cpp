// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonPickup.h"
#include "Components/SphereComponent.h"
#include "MainCharacter.h"

ABalloonPickup::ABalloonPickup()
{
	BalloonIncreaseAmount = 1;
	// CollisionVolume->SetWorldScale3D(FVector(4.5f, 4.5f, 4.5f));
	CollisionVolume->SetRelativeScale3D(FVector(5.f, 5.f, 5.f));
}

void ABalloonPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("ABalloonPickup::OnOverlapBegin"));

	AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
	if (MainCharacter) {
		MainCharacter->SetBalloonCount(BalloonIncreaseAmount);
	}

	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
