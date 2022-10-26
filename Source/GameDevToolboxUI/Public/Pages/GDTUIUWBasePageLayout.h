#pragma once

#include "CoreMinimal.h"
#include "Widgets/GDTUIUWBaseActivatableWidget.h"

#include "GDTUIUWBasePageLayout.generated.h"

class UCommonActivatableWidgetStack;

UCLASS(Abstract, ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Base Page Layout", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWBasePageLayout : public UGDTUIUWBaseActivatableWidget
{
    GENERATED_BODY()
public:

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* MainStack {};

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* PopupStack {};

};