// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

UTeacher::UTeacher()
{
	Name = TEXT("선선생님");
	Age = 30;
	id = 1111111;

}

void UTeacher::DoLesson()
{
	Super::DoLesson();

	UE_LOG(LogTemp, Log ,TEXT("%d 년차 %d %s 선생님 입니다 "), Age, id, *Name);

}
