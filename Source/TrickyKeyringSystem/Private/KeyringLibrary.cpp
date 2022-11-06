// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "KeyringLibrary.h"
#include "KeyringComponent.h"
#include "KeyType.h"

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

bool UKeyringLibrary::ActorUseKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType)
{
	if (!IsValid(OtherActor) || !KeyType)
	{
		return false;
	}
	
	if (!ActorHasKey(OtherActor, KeyType))
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
