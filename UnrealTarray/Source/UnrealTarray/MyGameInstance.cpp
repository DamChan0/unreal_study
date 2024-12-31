// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include <iostream>
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
	TCHAR FirstName[] = TEXT("김이박최정강조윤장임한오서신권황안송전홍");
	TCHAR LastName[] = TEXT("동민서연수현지영진석민주현우재승윤준호진영지은선영미희정훈영철민수혁태희경희은주은지현지수지혜수진미선미경");

	TArray<TCHAR> NameArray;
	NameArray.SetNum(3);
	NameArray[0] = FirstName[FMath::RandRange(0, 19)];
	NameArray[1] = LastName[FMath::RandRange(0, (UE_ARRAY_COUNT(LastName) - 1))];
	NameArray[2] = LastName[FMath::RandRange(0, (UE_ARRAY_COUNT(LastName) - 1))];

	return FString(NameArray.GetData());
}

void UMyGameInstance::Init()
{
	Super::Init(); // 존재이유 : 부모 클래스의 Init() 함수를 호출해야 한다.
	constexpr int32 ArrayNum = 10;

	TArray<int32> Int32Array;

	for (int32 i = 0; i < ArrayNum; ++i)
	{
		Int32Array.Add(i);
	}

	Int32Array.RemoveAll(
		[](int32 Element)
		{
			return Element % 2 == 0;
		}
	);

	for (int32 Element : Int32Array)
	{
		std::cout << Element << " ";
	}
	std::cout << std::endl;

	Int32Array += {2, 4, 6, 8, 10};


	int32 CArray[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	UE_LOG(LogTemp, Warning, TEXT("CArray[0]: %d"), CArray[0]);

	TArray<int32> Int32ArrayCompare;
	Int32ArrayCompare.AddUninitialized(ArrayNum);

	FMemory::Memcmp(Int32ArrayCompare.GetData(), CArray, ArrayNum * sizeof(int32));

	ensure(Int32ArrayCompare == Int32Array);

	int32 sum = 0;
	sum = Algo::Accumulate(Int32Array, 0);
	ensure(sum == 55);


	const int32 StudentNum = 300;
	for (int32 i= 1; i < StudentNum; ++i)
	{
		StudentArray.Emplace(FStudentData(MakeRandomName(), i));
	}
	TArray<FString> allStudentName;
	Algo::Transform(StudentArray, allStudentName,
	                [](const FStudentData& StudentData)
	                {
		                return StudentData.Name;
	                }
	);

	UE_LOG(LogTemp, Warning, TEXT("학생의 이름수 : %d"), allStudentName.Num());

	TSet<FString> AllUinqeName;
	Algo::Transform(StudentArray, AllUinqeName,
	                [](const FStudentData& StudentData)
	                {
		                return StudentData.Name;
	                }
	);

	UE_LOG(LogTemp, Warning, TEXT("학생의 이름수 : %d"), AllUinqeName.Num());
}
