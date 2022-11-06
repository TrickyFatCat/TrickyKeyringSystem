// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "KeyType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KeyringLibrary.generated.h"

class UKeyType;
class AActor;
class UKeyringComponent;
/**
 * 
 */
UCLASS()
class TRICKYKEYRINGSYSTEM_API UKeyringLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static UKeyringComponent* GetKeyringComponent(const AActor* OtherActor);
	
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static bool ActorHasKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	static bool ActorUseKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static FKeyData GetKeyData(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);
};
