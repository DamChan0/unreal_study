﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"

UPerson::UPerson()
{
	Name = TEXT("홍길동");
	Age = 20;
}

void UPerson::DoLesson()
{

	UE_LOG(LogTemp, Log, TEXT("%s님이 수업에 참여하였습니다."),*Name);
}

const FString& UPerson::GetName() const
{
	// TODO: insert return statement here
	return Name;
}

void UPerson::SetName(const FString& NewName)
{
	Name = NewName;
}