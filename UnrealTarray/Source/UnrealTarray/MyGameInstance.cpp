// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include <iostream>

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

	TArray<int32> Int32ArrayCompare;
	Int32ArrayCompare.AddUninitialized(ArrayNum);

	FMemory::Memcmp(Int32ArrayCompare.GetData(), CArray, ArrayNum * sizeof(int32));

	ensure(Int32ArrayCompare == Int32Array);
}
