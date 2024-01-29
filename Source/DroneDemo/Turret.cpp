// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	CollisionComp->InitCapsuleSize(25.f, 30.f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ATurret::OnHit);

	Health = 1.f;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::Fire()
{
	if (ProjectileClass)
	{
		FVector MuzzleLocation = GetActorLocation() + FTransform(GetActorRotation()).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = GetActorRotation();
		MuzzleRotation.Pitch += 10.0f;

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		ADroneDemoProjectile* Projectile = GetWorld()->SpawnActor<ADroneDemoProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		if (Projectile)
		{
			// Set the projectile's initial trajectory.
			FVector LaunchDirection = MuzzleRotation.Vector();
			Projectile->FireInDirection(LaunchDirection);
		}
	}
}

void ATurret::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ADroneDemoProjectile* HitBy = Cast<ADroneDemoProjectile>(OtherActor);
	if ((OtherActor != nullptr) && (OtherActor != this) && (HitBy != nullptr))
	{
		// Constant for now but can depend on different ammo types
		Health -= 0.255; 
		HitBy->Destroy();

		// Testing health reduction
		if (GEngine) { GEngine->AddOnScreenDebugMessage(2, 2.f, FColor::Yellow, FString::Printf(TEXT("Health left: %f"), Health)); }

		if (Health < 0) {
			Destroy();
		}
	}
}