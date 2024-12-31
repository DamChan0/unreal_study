// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
USTRUCT()
struct FStudentData
{
	GENERATED_BODY()
		
	FStudentData()
	{
		Name = TEXT("김동민");
		Order = -1 ;
	}
	FStudentData(FString InName, int order): Name(InName), Order(order)
	{}

	UPROPERTY()
	FString Name;

	UPROPERTY()
	int Order; 
	
	
};


UCLASS()
class UNREALTARRAY_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

private:
	TArray<FStudentData> StudentArray;
};
