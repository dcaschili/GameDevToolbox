#pragma once

#include "CoreMinimal.h"
#include "Pages/GDTUIUWBasePage.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWSimpleButtonListPage.generated.h"

class UGDTUIUWSimpleButtonList;

UCLASS(Abstract)
class GAMEDEVTOOLBOXUI_API UGDTUIUWSimpleButtonListPage : public UGDTUIUWBasePage
{
    GENERATED_BODY()
public:

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