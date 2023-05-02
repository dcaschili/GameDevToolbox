#pragma once

#include "Widgets/CommonActivatableWidgetContainer.h"

#include "GDTUIBaseActivatableWidgetStack.generated.h"

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Activatable Widget Stack Base", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIBaseActivatableWidgetStack : public UCommonActivatableWidgetStack
{
    GENERATED_BODY()

protected:
#if WITH_EDITOR	
	virtual const FText GetPaletteCategory() override;
#endif // WITH_EDITOR
};