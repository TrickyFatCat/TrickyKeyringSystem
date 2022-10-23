// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KeyringComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRICKYKEYRINGSYSTEM_API UKeyringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UKeyringComponent();

};
