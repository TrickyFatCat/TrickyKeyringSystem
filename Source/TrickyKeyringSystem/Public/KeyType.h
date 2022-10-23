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
UCLASS()
class TRICKYKEYRINGSYSTEM_API UKeyType : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintGetter, Category="KeyringSystem")
	bool GetDestroyOnUse() const;

	UFUNCTION(BlueprintGetter, Category="KeyringSystem")
	FKeyData GetKeyData() const;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetDestroyOnUse, Category="Key", meta=(AllowPrivateAccess))
	bool bDestroyOnUse = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetKeyData, Category="Key", meta=(AllowPrivateAccess))
	FKeyData KeyData;
};
