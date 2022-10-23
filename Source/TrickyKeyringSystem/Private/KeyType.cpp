// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "KeyType.h"

bool UKeyType::GetDestroyOnUse() const
{
	return bDestroyOnUse;
}

FKeyData UKeyType::GetKeyData() const
{
	return KeyData;
}
