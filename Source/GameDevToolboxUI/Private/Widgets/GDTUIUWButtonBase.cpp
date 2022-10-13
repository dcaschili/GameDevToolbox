#include "Widgets/GDTUIUWButtonBase.h"

#include "GDTUICategoryPaletteDefinitions.h"
#include "Widgets/GDTUITextBlockBase.h"
#include "GDTUILogCategories.h"

void UGDTUIUWButtonBase::NativeConstruct()
{
	Super::NativeConstruct();
	ApplyButtonConfiguration();
}

#if WITH_EDITOR	
const FText UGDTUIUWButtonBase::GetPaletteCategory()
{
    return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR

void UGDTUIUWButtonBase::ApplyButtonConfiguration()
{
	if (ButtonText)
	{
		ButtonText->SetContentText(ButtonConfiguration.ButtonText);
	}

	InnerApplyButtonConfiguration();
}