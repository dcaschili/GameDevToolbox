#pragma once

#include "Pages/GDTUIUWBasePage.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWSimpleButtonListPage.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGDTUIUWSimpleButtonListPageClicked, const FName&, ButtonId);

class UGDTUIUWSimpleButtonList;

UCLASS(Abstract)
class GAMEDEVTOOLBOXUI_API UGDTUIUWSimpleButtonListPage : public UGDTUIUWBasePage
{
    GENERATED_BODY()
public:

	FGDTUIUWSimpleButtonListPageClicked OnButtonClicked{};

protected:
	// UCommonActivatableWidget
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	// ~UCommonActivatableWidget

	// UGDTUIUWBasePage
	virtual void InnerOnActivated() override;
	virtual void InnerOnDeactivated() override;
	// ~UGDTUIUWBasePage

	virtual void InnerHandleButtonClicked(const FName& ButtonId) {}

private:
	UFUNCTION()
	void HandleButtonClicked(const FName& ButtonId);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UGDTUIUWSimpleButtonList> ButtonList{};
};