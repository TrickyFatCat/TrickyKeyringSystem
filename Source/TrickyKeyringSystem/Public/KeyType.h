// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KeyType.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FKeyData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="KeyData")
	FString KeyName{"Key"};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="KeyData")
	FLinearColor KeyColor{FLinearColor::Red};
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TRICKYKEYRINGSYSTEM_API UKeyType : public UObject
{
	GENERATED_BODY()

public:
	bool GetDestroyOnUse() const;

	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	void GetKeyData(FKeyData& Data) const;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Key", meta=(AllowPrivateAccess))
	bool bDestroyOnUse = false;
	
	UPROPERTY(EditDefaultsOnly, Category="Key", meta=(AllowPrivateAccess))
	FKeyData KeyData;
};
