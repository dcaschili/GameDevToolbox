#include "Widgets/GDTUITextBlockBase.h"

#include "GDTUICategoryPaletteDefinitions.h"
#include "Utils/GDTUITextFunctionLibrary.h"
#include "GDTUILogCategories.h"

void UGDTUITextBlockBase::SetContentText(const FName& InContent, bool bInUseContentAsTextId)
{
	ContentText = InContent;
	bUseContentAsTextId = bInUseContentAsTextId;

	UpdateText();
}

TSharedRef<SWidget> UGDTUITextBlockBase::RebuildWidget()
{
	TSharedRef<SWidget> SWidgetNew = Super::RebuildWidget();

	UpdateText();

	return SWidgetNew;
}


#if WITH_EDITOR	
const FText UGDTUITextBlockBase::GetPaletteCategory()
{
    return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR

void UGDTUITextBlockBase::UpdateText()
{
	if (!ContentText.IsNone())
	{
		if (bUseContentAsTextId)
		{
			const FText ConvertedText = UGDTUITextFunctionLibrary::GetTextById(this, ContentText);

			UE_LOG(GDTUILog, Verbose, TEXT("TextId: %s converted into: %s"), *ContentText.ToString(), *ConvertedText.ToString());

			SetText(ConvertedText);
		}
		else
		{
			SetText(FText::FromName(ContentText));
		}
	}
}
