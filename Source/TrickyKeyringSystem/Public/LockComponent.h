// MIT License Copyright (c) Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.generated.h"

class UKeyType;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLockChangedStateSignature);

/**
 * Controls locking/unlocking by a given key.
 */
UCLASS(ClassGroup=(TrickyKeyring), meta=(BlueprintSpawnableComponent))
class TRICKYKEYRINGSYSTEM_API ULockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULockComponent();

	/** Called then the component was locked. */
	UPROPERTY(BlueprintAssignable)
	FOnLockChangedStateSignature OnLocked;

	/** Called then the component was unlocked. */
	UPROPERTY(BlueprintAssignable)
	FOnLockChangedStateSignature OnUnlocked;

	/** Called then the component can't be locked. */
	UPROPERTY(BlueprintAssignable)
	FOnLockChangedStateSignature OnCantLocked;

	/** Called then the component can't be unlocked. */
	UPROPERTY(BlueprintAssignable)
	FOnLockChangedStateSignature OnCantUnlocked;

	/** Toggles if the component is locked on begin play. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LockComponent")
	bool bLockedOnStart = true;

	/** Locks the component. */
	UFUNCTION(BlueprintCallable, Category="LockComponent")
	bool Lock(AActor* TargetActor);

	/** Unlocks the component. */
	UFUNCTION(BlueprintCallable, Category="LockComponent")
	bool Unlock(AActor* TargetActor);

	UFUNCTION(BlueprintGetter, Category="LockComponent")
	bool GetIsLocked() const;

	/**Checks if the component can be locked/unlocked by a given actor. */
	UFUNCTION(BlueprintSetter, Category="LockComponent")
	bool CanUseLock(const AActor* TargetActor) const;

protected:
	virtual void BeginPlay() override;

	/** Key type which is required to lock/unlock the component. */
	UPROPERTY(EditAnywhere, Category="LockSettings", meta=(AllowPrivateAccess=true))
	TSubclassOf<UKeyType> RequiredKey = nullptr;

	/** Toggles if the key required to lock the component. */
	UPROPERTY(EditAnywhere, Category="LockSettings", meta=(AllowPrivateAccess=true))
	bool bLockingRequiresKey = true;

	/** Determines if the component is locked or not. */
	UPROPERTY(BlueprintGetter=GetIsLocked, Category="LockSettings")
	bool bIsLocked = true;

	void ToggleIsLocked(const bool Value);
};
