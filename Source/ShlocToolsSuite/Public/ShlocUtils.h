// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Font.h"
#include "ShlocUtils.generated.h"

class ABasePlayerController;

/**
 * 
 */
UCLASS()
class SHLOCTOOLSSUITE_API UShlocUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static UFont* LoadFontFromFilePath(FString InPath, FString InName, ABasePlayerController* Controller);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsPackagedGame(UObject* ObjectContext);

	UFUNCTION(BlueprintCallable)
		static FVector2D MeasureString(const FString& Text, const FSlateFontInfo & InFontInfo, float FontScale = 1.0f);

	UFUNCTION(BlueprintCallable)
		static FString GenerateHashOnString(const FString& InString);

	UFUNCTION(BlueprintCallable)
		static FString GetCurrentLine(const FString& InString);

	UFUNCTION(BlueprintCallable)
		static FString GenerateNumberOfNewlinesString(const int32 NumNewlines);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FString GetLineTerminator();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static float GetFontMaxHeight(UObject* InFont);

};
