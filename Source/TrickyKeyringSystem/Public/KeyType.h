// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KeyType.generated.h"

/**
 * Contains some information about the key for the HUD.
 */
USTRUCT(BlueprintType)
struct FKeyData
{
	GENERATED_BODY()

	/**
	 * The name of the key.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="KeyData")
	FString Name{"Key"};

	/**
	 * Color of the key.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="KeyData")
	FLinearColor Color{FLinearColor::Red};
};

/**
 * The object from which key classes must be inherited.
 */
UCLASS(Blueprintable, BlueprintType)
class TRICKYKEYRINGSYSTEM_API UKeyType : public UObject
{
	GENERATED_BODY()

public:

	/**
	 * Toggles if the key must be removed from the keyring after calling the UseKey function
	 */
	bool GetDestroyOnUse() const;

	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	void GetKeyData(FKeyData& Data) const;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Key", meta=(AllowPrivateAccess))
	bool bDestroyOnUse = false;
	
	UPROPERTY(EditDefaultsOnly, Category="Key", meta=(AllowPrivateAccess))
	FKeyData KeyData;
};
