#pragma once

#include "CoreMinimal.h"
#include "Widgets/GDTUIUWBaseActivatableWidget.h"
#include "Interfaces/GDTUIRefreshableInterface.h"

#include "GDTUIUWBasePage.generated.h"

UCLASS(Abstract, ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Base Page", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWBasePage : public UGDTUIUWBaseActivatableWidget
    , public IGDTUIRefreshableInterface
{
    GENERATED_BODY()
    
protected:
	// UGDTUIUWBaseActivatableWidget
	virtual void InnerSetupFirstFocus() override;
	// ~UGDTUIUWBaseActivatableWidget
};