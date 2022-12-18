// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.generated.h"

class UKeyType;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLockedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnlockedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCantLockSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCantUnlockSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRICKYKEYRINGSYSTEM_API ULockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULockComponent();

	UPROPERTY(BlueprintAssignable)
	FOnLockedSignature OnLocked;

	UPROPERTY(BlueprintAssignable)
	FOnUnlockedSignature OnUnlocked;

	UPROPERTY(BlueprintAssignable)
	FOnCantLockSignature OnCantLocked;

	UPROPERTY(BlueprintAssignable)
	FOnCantUnlockSignature OnCantUnlocked;

	UFUNCTION(BlueprintCallable, Category="LockComponent")
	bool Lock(AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category="LockComponent")
	bool Unlock(AActor* TargetActor);

	UFUNCTION(BlueprintGetter, Category="LockComponent")
	bool GetIsLocked() const;

	UFUNCTION(BlueprintSetter, Category="LockComponent")
	void SetIsLocked(bool Value);

	UFUNCTION(BlueprintSetter, Category="LockComponent")
	bool CanUnlock(const AActor* TargetActor) const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="LockSettings", meta=(AllowPrivateAccess=true))
	TSubclassOf<UKeyType> RequiredKey = nullptr;

	UPROPERTY(EditAnywhere, Category="LockSettings", meta=(AllowPrivateAccess=true))
	bool bLockRequiresKey = true;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetIsLocked, BlueprintSetter=SetIsLocked, Category="LockSettings")
	bool bIsLocked = true;

	void ToggleIsLocked(const bool Value);
};
