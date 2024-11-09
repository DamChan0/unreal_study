// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Person.h"
#include "LessenInterface.h"
#include "Student.generated.h"


/**
 * 
 */
UCLASS()
class UNREALINTERFACE_API UStudent : public UPerson, public ILessenInterface
{
	GENERATED_BODY()

public:
	UStudent();
	
	virtual void DoLessen() override;
};
