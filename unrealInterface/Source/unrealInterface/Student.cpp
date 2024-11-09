// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("학생1");
}

void UStudent::DoLessen()
{
	// ILessenInterface::DoLessen();
	UE_LOG(LogTemp, Warning, TEXT("%s 학생이 수업을 듣습니다."), *Name);
}

