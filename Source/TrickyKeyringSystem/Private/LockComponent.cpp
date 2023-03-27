// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "LockComponent.h"

#include "KeyringLibrary.h"

ULockComponent::ULockComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool ULockComponent::Lock(AActor* TargetActor)
{
	if (bIsLocked)
	{
		return false;
	}

	if (!bLockingRequiresKey)
	{
		ToggleIsLocked(true);
		return true;
	}
	
	if (IsValid(TargetActor))
	{
		return false;
	}

	if (UKeyringLibrary::UseKey(TargetActor, RequiredKey))
	{
		ToggleIsLocked(true);
		return true;
	}

	OnCantLocked.Broadcast();
	return false;
}

bool ULockComponent::Unlock(AActor* TargetActor)
{
	if (!bIsLocked || !IsValid(TargetActor))
	{
		return false;
	}

	if(UKeyringLibrary::UseKey(TargetActor, RequiredKey))
	{
		ToggleIsLocked(false);
		return true;
	}

	OnCantUnlocked.Broadcast();
	return false;
}

bool ULockComponent::GetIsLocked() const
{
	return bIsLocked;
}

bool ULockComponent::CanUseLock(const AActor* TargetActor) const
{
	if (!IsValid(TargetActor) || !RequiredKey)
	{
		return false;
	}

	return UKeyringLibrary::ActorHasKey(TargetActor, RequiredKey);
}


void ULockComponent::BeginPlay()
{
	Super::BeginPlay();

	bIsLocked = bLockedOnStart;
}

void ULockComponent::ToggleIsLocked(const bool Value)
{
	if (bIsLocked == Value)
	{
		return;
	}

	bIsLocked = Value;
	bIsLocked ? OnLocked.Broadcast() : OnUnlocked.Broadcast();
}
