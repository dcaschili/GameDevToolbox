#include "Widgets/GDTUITextBlockBase.h"

#include "GDTUICategoryPaletteDefinitions.h"
#include "Utils/GDTUITextFunctionLibrary.h"
#include "GDTUILogCategories.h"

TSharedRef<SWidget> UGDTUITextBlockBase::RebuildWidget()
{
	TSharedRef<SWidget> SWidgetNew = Super::RebuildWidget();

	if(bUseContentAsTextId && !ContentText.IsNone())
	{
		const FText ConvertedText = UGDTUITextFunctionLibrary::GetTextById(this, ContentText);

		UE_LOG(GDTUITextDataLog, Verbose, TEXT("TextId: %s converted into: %s"), *ContentText.ToString(), *ConvertedText.ToString());

		SetText(ConvertedText);
	}

	return SWidgetNew;
}


#if WITH_EDITOR	
const FText UGDTUITextBlockBase::GetPaletteCategory()
{
    return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR
