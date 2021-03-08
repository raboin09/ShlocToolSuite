// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHLOCTOOLSSUITE_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

		void Shutdown() override;

		UFUNCTION(BlueprintCallable)
			void DeleteTempDir();

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			FString TempDir;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			bool bShouldDeleteTempDir;
};
