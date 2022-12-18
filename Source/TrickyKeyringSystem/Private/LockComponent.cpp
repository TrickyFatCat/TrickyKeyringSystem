// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


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

	if (!bLockRequiresKey)
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

void ULockComponent::SetIsLocked(const bool Value)
{
	bIsLocked = Value;
}


void ULockComponent::BeginPlay()
{
	Super::BeginPlay();
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
