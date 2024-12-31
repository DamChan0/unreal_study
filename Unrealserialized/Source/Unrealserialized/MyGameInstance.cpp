// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"


UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::Init() // play in editor or play in standalone
{
	Super::Init();

	FStudentData RawData(1, TEXT("김동민"));

	const FString SavePath = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("SaveData"));
	// ProjectDir() : 프로젝트 디렉토리 경로를 반환한다.
	// Combine() : 경로를 합쳐준다.

	UE_LOG(LogTemp, Warning, TEXT("SavePath : %s"), *SavePath);

	const FString RawDataFile(TEXT("RawData.bin"));
	FString RawDataAbsolutePath = FPaths::Combine(SavePath, RawDataFile);

	UE_LOG(LogTemp, Warning, TEXT("RawDataFile Path :  %s " ), *RawDataAbsolutePath);
	FPaths::MakeStandardFilename(RawDataAbsolutePath);

	UE_LOG(LogTemp, Warning, TEXT("Normalized RawDataFile Path :  %s " ), *RawDataAbsolutePath);

	FArchive* RawDataWrite = IFileManager::Get().CreateFileWriter(*RawDataAbsolutePath);
	if(RawDataWrite != nullptr)
	{
		*RawDataWrite << RawData;
		RawDataWrite->Close(); 
		delete RawDataWrite;
		RawDataWrite = nullptr;
	}
	FArchive* RawFileReader = IFileManager::Get().CreateFileReader(*RawDataAbsolutePath);
	if(RawFileReader != nullptr)
	{
		FStudentData RawDataDst;
		*RawFileReader << RawDataDst;
		RawFileReader->Close();
		delete RawFileReader;
		RawFileReader = nullptr;

		UE_LOG(LogTemp , Warning, TEXT("[RawDATA] 이름 %s 순번 %d "), *RawDataDst.Name, RawDataDst.Order);

		
	}
	
}
