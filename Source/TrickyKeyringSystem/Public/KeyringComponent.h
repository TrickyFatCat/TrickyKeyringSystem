// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "KeyType.h"
#include "Components/ActorComponent.h"
#include "KeyringComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyActionPerformedSignature, UKeyType*, Key);

/**
 * A component which manages keys the player got.
 */
UCLASS(ClassGroup=(TrickyKeyring), meta=(BlueprintSpawnableComponent))
class TRICKYKEYRINGSYSTEM_API UKeyringComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UKeyringComponent();

	/**
	 * Called when the key was successfully added to the keyring.
	 */
	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyActionPerformedSignature OnKeyAdded;

	/**
	 * Called when the key was successfully removed from the keyring.
	 */
	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyActionPerformedSignature OnKeyUsed;

	/**
	 * Called when the key was successfully used.
	 */
	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyActionPerformedSignature OnKeyRemoved;

	/**
	 * Adds a key of a given class to the keyring.
	 *
	 * Returns true if the key was added.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool AddKey(TSubclassOf<UKeyType> KeyType);

	/**
	 * Removes a key of a given class from the keyring.
	 *
	 * Returns true if the key was removed.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool RemoveKey(TSubclassOf<UKeyType> KeyType);

	/**
	 * Removes all keys in the keyring.
	 *
	 * Returns true if all keys were removed.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool RemoveAllKeys();

	/**
	 * Calls the OnKeyUsed delegate and removes a key of a given class if DestroyOnUse == true.
	 *
	 * Returns true if the key was successfully used.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool UseKey(TSubclassOf<UKeyType> KeyType);

	/**
	 * Checks if the keyring array is empty.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool KeyringIsEmpty() const;

	/**
	 * Checks if the keyring has a key of a given class.
	 */
	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool HasKey(TSubclassOf<UKeyType> KeyType);

	/**
	 * Returns key data structure by index of the key in the array.
	 */
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	bool GetKeyDataByIndex(const int32 Index, FKeyData& KeyData);

	/**
	 * Returns key data structure by given class of the key.
	 */
	UFUNCTION(BlueprintPure, Category="KeyringSystem")
	bool GetKeyDataByClass(const TSubclassOf<UKeyType> KeyType, FKeyData& KeyData);

	UKeyType* GetKey(const TSubclassOf<UKeyType> KeyType);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Keyring", meta=(AllowPrivateAccess))
	TArray<UKeyType*> Keyring;
};
