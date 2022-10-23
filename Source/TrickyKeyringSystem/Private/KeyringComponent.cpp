// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "KeyringComponent.h"

UKeyringComponent::UKeyringComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UKeyringComponent::AddKey(TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(KeyType))
	{
		return false;
	}

	if (HasKey(KeyType))
	{
		return false;
	}

	UKeyType* NewKey = NewObject<UKeyType>(this, *KeyType);
	Keyring.Emplace(NewKey);
	OnKeyAdded.Broadcast(NewKey);
	
	return true;
}

bool UKeyringComponent::RemoveKey(const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(KeyType))
	{
		return false;
	}

	if (!HasKey(KeyType))
	{
		return false;
	}

	UKeyType* Key = GetKey(KeyType);

	if (!IsValid(Key))
	{
		return false;
	}

	Keyring.Remove(Key);
	OnKeyRemoved.Broadcast(Key);
	Key->ConditionalBeginDestroy();
	
	return true;
}

bool UKeyringComponent::UseKey(TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(KeyType))
	{
		return false;
	}

	if (!HasKey(KeyType))
	{
		return false;
	}

	UKeyType* Key = GetKey(KeyType);

	if (!IsValid(Key))
	{
		return false;
	}

	OnKeyUsed.Broadcast(Key);

	if (Key->GetDestroyOnUse())
	{
		RemoveKey(KeyType);
	}

	return true;
}

bool UKeyringComponent::KeyringIsEmpty() const
{
	return Keyring.Num() == 0;
}

bool UKeyringComponent::HasKey(const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(KeyType))
	{
		return false;
	}

	auto Predicate = [&](const UKeyType* Key) { return Key->IsA(KeyType); };
	return Keyring.ContainsByPredicate(Predicate);
}

void UKeyringComponent::GetKeyDataByIndex(const int32 Index, FKeyData& KeyData)
{
	if (KeyringIsEmpty())
	{
		return;
	}

	if (Index < 0 || Index >= Keyring.Num())
	{
		return;
	}

	const UKeyType* Key = Keyring[Index];

	if (!IsValid(Key))
	{
		return;
	}
	
	KeyData = Key->GetKeyData();
}

void UKeyringComponent::GetKeyDataByClass(const TSubclassOf<UKeyType> KeyType, FKeyData& KeyData)
{
	if (KeyringIsEmpty())
	{
		return;
	}

	if (!HasKey(KeyType) || !IsValid(KeyType))
	{
		return;
	}

	auto Predicate = [&](const UKeyType* Key) { return Key->IsA(KeyType); };
	const UKeyType* Key = *Keyring.FindByPredicate(Predicate);

	if (!IsValid(Key))
	{
		return;
	}
	
	KeyData = Key->GetKeyData();
}

UKeyType* UKeyringComponent::GetKey(const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(KeyType))
	{
		return nullptr;
	}
	
	auto Predicate = [&](const UKeyType* Key) { return Key->IsA(KeyType); };
	return *Keyring.FindByPredicate(Predicate);
}
