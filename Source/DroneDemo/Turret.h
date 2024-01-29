// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DroneDemoProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Turret.generated.h"

UCLASS()
class DRONEDEMO_API ATurret : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Collision component
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UCapsuleComponent* CollisionComp;

	// Health counter 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	float Health;

	// Turret firing capacity
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ADroneDemoProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	FVector MuzzleOffset;

	UFUNCTION(BlueprintCallable)
	void Fire();

	// Being hit by projectile
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
