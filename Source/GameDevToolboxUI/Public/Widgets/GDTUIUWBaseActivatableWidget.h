#pragma once

#include "CommonActivatableWidget.h"

#include "GDTUIUWBaseActivatableWidget.generated.h"

UCLASS(Abstract, ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Base Activatable Widget", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWBaseActivatableWidget : public UCommonActivatableWidget
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
	*/
	virtual void InnerSetupFirstFocus() {}

private:
	UPROPERTY(EditDefaultsOnly, Category="GDTUI|Focus")
	bool bNeedFirstFocusSetup = true;

};