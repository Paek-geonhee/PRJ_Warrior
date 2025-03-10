// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Param to get owner must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const {
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Param to get controller must be derived from AController");
		return GetOwningPawn()->GetController<T>();
		// 왜 이렇게 함 굳이? / 문제 생기면 확인해봐야 할 위치
	}
};

