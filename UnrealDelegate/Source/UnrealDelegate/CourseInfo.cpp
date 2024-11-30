// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
 Content = TEXT("동민 대학교, 학사 2024 2학기 말");	
}

void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& NewContents)
{
 Content = NewContents;

 UE_LOG(LogTemp, Warning, TEXT("%s의 새로운 정보: %s"), *InSchoolName, *NewContents);
 OnChanged.Broadcast(InSchoolName, NewContents);
}
