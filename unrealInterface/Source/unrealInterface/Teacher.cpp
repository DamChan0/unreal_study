// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

UTeacher::UTeacher()
{
	Name = TEXT("선생님1");
}

void UTeacher::DoLessen()
{
	// ILessenInterface::DoLessen();
	UE_LOG(LogTemp, Warning, TEXT("%s 선생님이 수업을 합니다."), *Name);
}

