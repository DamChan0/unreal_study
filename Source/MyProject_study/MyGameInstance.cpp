// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"


UMyGameInstance::UMyGameInstance() 
{
	SchoolName = TEXT("동민 대학교"); // 앤진이 초기화되는 시점에서 설정이된다
}

void UMyGameInstance::Init() {
    Super::Init();


	UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance::Init() called"));
	UE_LOG(LogTemp, Log, TEXT("+++++++++++++++++++++++++++++++++++++"));

	UClass* ClassRunTime = GetClass();
	UClass* ClassCompileTime = UMyGameInstance::StaticClass();
	//check(ClassRunTime != ClassCompileTime);
	//ensureMsgf(ClassRunTime != ClassCompileTime, TEXT("에러발생"));  // 에디터가 종료되지 않고 사용할 수 있도록함 



	UE_LOG(LogTemp, Log, TEXT("ClassRunTime 학교이름 : %s"), *ClassRunTime->GetName());
	UE_LOG(LogTemp, Log, TEXT("ClassCompileTime: %s"), *ClassCompileTime->GetName());
   

	
	//SchoolName = "Korea University";
	SchoolName = TEXT("Korea University");
	UE_LOG(LogTemp, Log, TEXT("SchoolName : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("기본 값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);
   
	UE_LOG(LogTemp, Log, TEXT("+++++++++++++++++++++++++++++++++++++"));


	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();
	Student->SetName(TEXT("학생1  "));
	UE_LOG(LogTemp, Log, TEXT("학생 이름 : %s"), *Student->GetName());

	FProperty* NameProperty = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	FString newName1(TEXT("선생님1"));
	FString newName2(TEXT("김동민"));

	if (NameProperty) {
		NameProperty->GetValue_InContainer(Teacher, &newName1);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 : %s"), *newName1);
		NameProperty->SetValue_InContainer(Teacher, &newName2);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 : %s"), *Teacher->GetName());

	}
	UE_LOG(LogTemp, Log, TEXT("+++++++++++++++++++++++++++++++++++++"));

	Student->DoLesson();
	UFunction* DoLessonFunction = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if (DoLessonFunction) {
		Teacher->ProcessEvent(DoLessonFunction, nullptr);

	}


}
