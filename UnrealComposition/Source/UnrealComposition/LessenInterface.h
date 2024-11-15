// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LessenInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULessenInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREALCOMPOSITION_API ILessenInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void DoLessen()
	{
		UE_LOG(LogTemp, Warning, TEXT("수업을 듣습니다.")); // 인터페이스의 기본 구현
	}// 자식 클래스들은 이 함수를 반드시 구현해야한다.
};
 