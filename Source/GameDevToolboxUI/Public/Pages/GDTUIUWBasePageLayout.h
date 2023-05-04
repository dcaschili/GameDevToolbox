#pragma once

#include "CoreMinimal.h"
#include "Widgets/GDTUIUWBaseActivatableWidget.h"

#include "GDTUIUWBasePageLayout.generated.h"

class UCommonActivatableWidgetStack;

UENUM(BlueprintType)
enum class EPageLayoutStackType : uint8
{
	Main	UMETA(DisplayName = "Menu"),
	Popup	UMETA(DisplayName = "Popup"),
	GameUI	UMETA(DisplayName = "Game")
};

UCLASS(Abstract)
class GAMEDEVTOOLBOXUI_API UGDTUIUWBasePageLayout : public UGDTUIUWBaseActivatableWidget
{
    GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Page Layout")
	UCommonActivatableWidget* PushWidget(TSubclassOf<UGDTUIUWBaseActivatableWidget> InWidgetClass, EPageLayoutStackType InStackType = EPageLayoutStackType::Main);
	
	UFUNCTION(BlueprintCallable, Category = "Page Layout")
	UCommonActivatableWidget* GetActiveWidget(EPageLayoutStackType InStackType) const;

protected:
	/** Used for menu pages */
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* MainStack {};

	/** Used for gameplay HUD */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameUIStack{};

	// TODO: Decide if it is useful to have a menu and a gameplay stack for popups. To separate them.
	/** Used for popup during gameplay or menu. */
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UCommonActivatableWidgetStack* PopupStack {};

private:
	UCommonActivatableWidgetStack* GetWidgetStackByType(EPageLayoutStackType InStackType) const;
};