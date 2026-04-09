// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPShooter_Gam415PickUpComponent.h"

UFPShooter_Gam415PickUpComponent::UFPShooter_Gam415PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UFPShooter_Gam415PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UFPShooter_Gam415PickUpComponent::OnSphereBeginOverlap);
}

void UFPShooter_Gam415PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AFPShooter_Gam415Character* Character = Cast<AFPShooter_Gam415Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
