// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
    SchoolName = TEXT("동민 대학교"); // 앤진이 초기화되는 시점에서 설정이된다
}

void UMyGameInstance::Init()
{
    Super::Init();

    TArray<UPerson*> Persons = {NewObject<UStaff>(), NewObject<UStudent>(), NewObject<UTeacher>()};
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    for(const auto  Person : Persons)
    {
        UE_LOG(LogTemp, Warning, TEXT("이름: %s"), *Person->GetName());
    }
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));

    for(const auto person : Persons)
    {
        ILessenInterface* LessenInterface = Cast<ILessenInterface>(person);
        if(!LessenInterface)
        {
            UE_LOG(LogTemp, Warning, TEXT("%s 는 수업을 들을 수 없습니다,"), *person->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("%s 는 수업을 들을 수 있습니다."), *person->GetName());
            LessenInterface->DoLessen();
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));

}
