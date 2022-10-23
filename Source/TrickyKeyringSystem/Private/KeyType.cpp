// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "KeyType.h"

bool UKeyType::GetDestroyOnUse() const
{
	return bDestroyOnUse;
}

void UKeyType::GetKeyData(FKeyData& Data) const
{
	Data = KeyData;
}
