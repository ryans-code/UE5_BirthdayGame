// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MainCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class HAPPYBIRTHDAY_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	// Follow camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	AMainCharacter();

	FORCEINLINE int32 GetCandleCount() { return CandleCount; }
	FORCEINLINE void SetCandleCount(int32 Amount) { CandleCount = CandleCount + Amount; }
	FORCEINLINE int32 GetBalloonCount() { return BalloonCount; }
	FORCEINLINE void SetBalloonCount(int32 Amount) { BalloonCount = BalloonCount + Amount; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// My code starts here
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* MainCharMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int32 CandleCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int32 BalloonCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		int32 JumpCount;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float WalkSpeed = 600.f;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float SprintSpeed = 1200.f;

	void Walk();
	void Sprint();
	void Jump();
	void Landed(const FHitResult& Hit) override;
};
