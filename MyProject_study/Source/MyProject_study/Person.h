// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_STUDY_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
	UPerson();

	UFUNCTION()	


	virtual void DoLesson();
	const FString& GetName() const;
	void SetName(const FString& NewName);


protected:
	UPROPERTY() 
	FString Name;

	UPROPERTY()
	int32 Age;

private:
};
