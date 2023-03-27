// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov


#include "KeyringLibrary.h"
#include "KeyringComponent.h"
#include "KeyType.h"
#include "GameFramework/Actor.h"

UKeyringComponent* UKeyringLibrary::GetKeyringComponent(const AActor* OtherActor)
{
	if (!IsValid(OtherActor))
	{
		return nullptr;
	}

	return OtherActor->FindComponentByClass<UKeyringComponent>();
}

bool UKeyringLibrary::ActorHasKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	return KeyringComponent->HasKey(KeyType);
}

bool UKeyringLibrary::AddKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}
	
	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	return KeyringComponent->AddKey(KeyType);
}

bool UKeyringLibrary::UseKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}
	
	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	return KeyringComponent->UseKey(KeyType);
}

UKeyType* UKeyringLibrary::GetKeyObject(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return nullptr;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return nullptr;
	}

	return KeyringComponent->GetKey(KeyType);
}

FKeyData UKeyringLibrary::GetKeyData(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	FKeyData KeyData{"KEY_NONE", FLinearColor::Red};
	
	if (!IsValid(OtherActor) || !KeyType)
	{
		return KeyData;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return KeyData;
	}

	KeyringComponent->GetKeyDataByClass(KeyType, KeyData);
	
	return KeyData;
}

bool UKeyringLibrary::IsKeyDestroyable(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	const UKeyType* Key = GetKeyObject(OtherActor, KeyType);

	if (!IsValid(Key))
	{
		return false;
	}

	return Key->GetDestroyOnUse();
}

bool UKeyringLibrary::RemoveKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	return KeyringComponent->RemoveKey(KeyType);
}

bool UKeyringLibrary::RemoveAllKeys(const AActor* OtherActor)
{
	if (!IsValid(OtherActor))
	{
		return false;
	}

	UKeyringComponent* KeyringComponent = GetKeyringComponent(OtherActor);

	if (!KeyringComponent)
	{
		return false;
	}

	return KeyringComponent->RemoveAllKeys();
}
