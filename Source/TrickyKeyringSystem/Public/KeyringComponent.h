// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "KeyType.h"
#include "Components/ActorComponent.h"
#include "KeyringComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyAddedSignature, UKeyType*, Key);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyUsedSignature, UKeyType*, Key);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyRemovedSignature, UKeyType*, Key);

UCLASS(ClassGroup=(TrickyKeyring), meta=(BlueprintSpawnableComponent))
class TRICKYKEYRINGSYSTEM_API UKeyringComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UKeyringComponent();

	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyAddedSignature OnKeyAdded;

	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyUsedSignature OnKeyUsed;

	UPROPERTY(BlueprintAssignable, Category="KeyringSystem")
	FOnKeyRemovedSignature OnKeyRemoved;

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool AddKey(TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool RemoveKey(TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool UseKey(TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool KeyringIsEmpty() const;

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	bool HasKey(TSubclassOf<UKeyType> KeyType);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	void GetKeyDataByIndex(const int32 Index, FKeyData& KeyData);

	UFUNCTION(BlueprintCallable, Category="KeyringSystem")
	void GetKeyDataByClass(const TSubclassOf<UKeyType> KeyType, FKeyData& KeyData);

	UKeyType* GetKey(const TSubclassOf<UKeyType> KeyType);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Keyring", meta=(AllowPrivateAccess))
	TArray<UKeyType*> Keyring;
};
