// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Person.h"
#include "LessenInterface.h"
#include "Teacher.generated.h"


/**
 * 
 */
UCLASS()
class UNREALINTERFACE_API UTeacher : public UPerson, public ILessenInterface
{
	GENERATED_BODY()
public:
	UTeacher();

	virtual void DoLessen() override;
};