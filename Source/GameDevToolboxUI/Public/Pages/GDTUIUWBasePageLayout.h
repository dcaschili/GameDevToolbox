#pragma once

#include "CoreMinimal.h"
#include "Widgets/GDTUIUWBaseActivatableWidget.h"

#include "GDTUIUWBasePageLayout.generated.h"

class UCommonActivatableWidgetStack;

UENUM(BlueprintType)
enum class EPageLayoutStackType : uint8
{
	Main,
	Popup
};

UCLASS(Abstract)
class GAMEDEVTOOLBOXUI_API UGDTUIUWBasePageLayout : public UGDTUIUWBaseActivatableWidget
{
    GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Page Layout")
	UCommonActivatableWidget* PushWidget(TSubclassOf<UGDTUIUWBaseActivatableWidget> InWidgetClass, EPageLayoutStackType InStackType = EPageLayoutStackType::Main);

protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* MainStack {};

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* PopupStack {};

private:
	UCommonActivatableWidgetStack* GetWidgetStackByType(EPageLayoutStackType InStackType);
};