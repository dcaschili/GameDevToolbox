#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Interfaces/GDTUIRefreshableInterface.h"

#include "GDTUIUWBasePage.generated.h"

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Base Page", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWBasePage : public UCommonActivatableWidget
    , public IGDTUIRefreshableInterface
{
    GENERATED_BODY()

protected:
    // UCommonActivatableWidget
    virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
    // ~UCommonActivatableWidget

	/** Override this method to perform OnActivation setup for the page. */
	virtual void InnerOnActivated() {}
	virtual void InnerOnDeactivated() {}
	
	/** 
		Called after InnerOnActivated. Override to handle first focus.
		By default it calls GetDesiredFocusTarget() and calls SetFocus().
	*/
	virtual void InnerSetupFirstFocus();
};