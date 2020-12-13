
#include "ShlocUtils.h"
#include "Fonts/CompositeFont.h"
#include "BasePlayerController.h"
#include "Engine/EngineTypes.h"
#include "Misc/SecureHash.h"
#include "Kismet/KismetStringLibrary.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "Fonts/FontMeasure.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"

UFont* UShlocUtils::LoadFontFromFilePath(FString InPath, FString InName, ABasePlayerController* Controller)
{
	UFontFace* FontFace = NewObject<UFontFace>();
	FontFace->LoadingPolicy = EFontLoadingPolicy::Inline;
	FontFace->FontFaceData = FFontFaceData::MakeFontFaceData(Controller->LoadBytesFromFile(InPath, InName));

	UFont* Font = NewObject<UFont>();
	Font->FontCacheType = EFontCacheType::Runtime;
	FTypefaceEntry& TypefaceEntry = Font->CompositeFont.DefaultTypeface.Fonts[Font->CompositeFont.DefaultTypeface.Fonts.AddDefaulted()];
	TypefaceEntry.Font = FFontData(FontFace);

	return Font;
}

bool UShlocUtils::IsPackagedGame(UObject* ObjectContext)
{
	if (ensure(ObjectContext)) {
		if (ensure(ObjectContext->GetWorld())) {
			return ObjectContext->GetWorld()->WorldType == EWorldType::Game;
		}
	}
	return false;
}

FVector2D UShlocUtils::MeasureString(const FString& Text, const FSlateFontInfo & InFontInfo, float FontScale)
{
	const TSharedRef<FSlateFontMeasure> FontMeasure = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	return FontMeasure->Measure(Text, InFontInfo, FontScale);
}

FString UShlocUtils::GenerateHashOnString(const FString& InString)
{
	const TCHAR* StringConvert = *InString;
	return FMD5::HashAnsiString(StringConvert);
}

FString UShlocUtils::GetCurrentLine(const FString& InString)
{
	if (InString.Contains(LINE_TERMINATOR)) {
		int32 NewLineIndex = UKismetStringLibrary::FindSubstring(InString, LINE_TERMINATOR, false, true);
		const TCHAR* Blank = *FString("");
		FString ChoppedString = InString.RightChop(NewLineIndex).Replace(LINE_TERMINATOR, Blank);
		return ChoppedString;
	}
	return InString;
}  

FString UShlocUtils::GenerateNumberOfNewlinesString(const int32 NumNewlines)
{
	FString RetString = "";
	for (int i = 0; i < NumNewlines; i++) {
		RetString.Append("\n");
	}
	return RetString;
}

FString UShlocUtils::GetLineTerminator()
{
	return LINE_TERMINATOR;
}

float UShlocUtils::GetFontMaxHeight(UObject* InFont)
{
	UFont* TempFont = Cast<UFont>(InFont);
	if (TempFont) {
		return TempFont->GetMaxCharHeight();
	}
	return 0.f;
}