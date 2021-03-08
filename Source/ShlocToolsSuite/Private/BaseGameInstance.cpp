// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseGameInstance.h"
#include "HAL/PlatformFilemanager.h"

void UBaseGameInstance::Shutdown()
{
	if (bShouldDeleteTempDir) {
		DeleteTempDir();
	}
	Super::Shutdown();
}

void UBaseGameInstance::DeleteTempDir()
{
	bool bDidDel = FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*TempDir);
	if (bDidDel) {
		UE_LOG(LogTemp, Warning, TEXT("Dir deleted!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ERROR did not delete"));
	}
}
