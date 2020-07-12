// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

UCLASS()
class SHLOCTOOLSSUITE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
		TArray<uint8> LoadBytesFromFile(const FString& DirPath, const FString& FileName);

};
