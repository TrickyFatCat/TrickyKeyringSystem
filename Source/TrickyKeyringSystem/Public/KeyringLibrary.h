// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "KeyType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KeyringLibrary.generated.h"

class UKeyType;
class AActor;
class UKeyringComponent;

/**
 * A library with useful functions to work with KeyringComponent.
 */
UCLASS()
class TRICKYKEYRINGSYSTEM_API UKeyringLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**Returns KeyringComponent if the given actor has it.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static UKeyringComponent* GetKeyringComponent(const AActor* OtherActor);

	/**Checks if the given actor has key in KeyringComponent.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static bool ActorHasKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Adds key to KeyringComponent.*/
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	static bool AddKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Force the given actor to use the give key class.*/
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	static bool UseKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Returns a key object from KeyringComponent of the given actor.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static UKeyType* GetKeyObject(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Returns key data from `KeyringComponent` of the given actor.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static FKeyData GetKeyData(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Checks if the given key class is destroyable.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static bool IsKeyDestroyable(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Removes key from KeyringComponent.*/
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	static bool RemoveKey(const AActor* OtherActor, const TSubclassOf<UKeyType> KeyType);

	/**Removes all keys form `KeyringComponent` of the given actor.*/
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	static bool RemoveAllKeys(const AActor* OtherActor);
};
