// Fill out your copyright notice in the Description page of Project Settings.

#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("홍길동학생");

	Age = 1;
	id = 20171185;
}

void UStudent::DoLesson()
{
	Super::DoLesson();

	UE_LOG(LogTemp, Log, TEXT("%d학년 %d번 %s학생이 수업에 참여하였습니다."), Age, id, *Name);
}
