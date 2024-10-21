// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "MainCharacter.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (Pawn == nullptr) {
		Pawn = TryGetPawnOwner();
		if (Pawn) {
			Main = Cast<AMainCharacter>(Pawn);
		}
	}

	bIsDescending = false;
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr) {
		Pawn = TryGetPawnOwner();
	}

	if (Pawn) {
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
		float ZSpeed = Speed.Z;

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
		ZSpeed < 0 ? bIsDescending = true : bIsDescending = false;

		if (Main == nullptr) {
			Main = Cast<AMainCharacter>(Pawn);
		}

		if (Main) {
			if(Main->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0) {
				bIsAccelerating = true;
			}
			else {
				bIsAccelerating = false;
			}

			FVector Start = FVector(Main->GetCapsuleComponent()->GetComponentLocation()) - FVector(0.f, 0.f, Main->GetCapsuleComponent()->GetScaledCapsuleHalfHeight());
			FVector End = FVector(Main->GetCapsuleComponent()->GetComponentLocation()) - FVector(0.f, 0.f, 5000.f);
			FHitResult Hit;
			FCollisionObjectQueryParams ObjectQueryParams;
			ObjectQueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);

			GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, ObjectQueryParams);
			// DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f, 0U, 2.f);
			HeightAboveGround = Hit.Distance;
		}

		
	}
}
