// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "CourseInfo.h"
#include "Person.h" // Assuming UPerson is defined here
#include "Student.h" // Assuming UStudent is defined here
#include "Teacher.h" // Assuming UTeacher is defined here
#include "Staff.h" // Assuming UStaff is defined here
#include "Card.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();
	CourseInfo = NewObject<UCourseInfo>();

	UStudent* Student1 = NewObject<UStudent>();
	UStudent* Student2 = NewObject<UStudent>();
	UStudent* Student3 = NewObject<UStudent>();

	Student1->SetName(TEXT("학생1"));
	Student2->SetName(TEXT("학생2"));
	Student3->SetName(TEXT("학생3"));


	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetCourseNoti);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetCourseNoti);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetCourseNoti);

	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("2024 2학기 학사"));
	
}
