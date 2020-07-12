
#include "ShlocUtils.h"
#include "Fonts/CompositeFont.h"
#include "BasePlayerController.h"
#include "Engine/EngineTypes.h"
#include "Misc/SecureHash.h"
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
