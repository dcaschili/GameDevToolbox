#pragma once

#include "Widgets/GDTUIUWBaseActivatableWidget.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWSimpleButtonList.generated.h"

class UGDTUIUWButtonBase;
class UVerticalBox;
class UCommonButtonBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGDTUIButtonListClicked, const FName&, ButtonId);

UCLASS(BlueprintType, Blueprintable, Abstract, ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Simple Button List", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWSimpleButtonList : public UGDTUIUWBaseActivatableWidget	
{
	GENERATED_BODY()
public:
	void SetButtonsConfiguration(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration);

	FGDTUIButtonListClicked OnButtonListClickedDelegate{};

protected:

	// UCommonActivatableWidget
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	// ~UCommonActivatableWidget

	// UGDTUIBaseActivatableWidget
	virtual void InnerOnActivated() override;
	virtual void InnerOnDeactivated() override;
	// ~UGDTUIBaseActivatableWidget

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UVerticalBox> ButtonsVerticalBoxContainer{};

	UPROPERTY(EditInstanceOnly, Category = "UI")
	TSubclassOf<UGDTUIUWButtonBase> ButtonClass{};
	UPROPERTY(EditInstanceOnly, Category = "UI|Configuration", meta = (TitleProperty = "ButtonId"))
	TArray<FGDTUIButtonConfiguration> DefaultButtonsConfiguration{};
	UPROPERTY(EditAnywhere, Category = "UI")
	bool bSeparateButtonsWithSpacers = true;
	UPROPERTY(EditAnywhere, Category = "UI", meta = (EditCondition = "bSeparateButtonsWithSpacers"))
	FVector2D SpacerSize {0.0f, 32.0f};

	TOptional<TArray<FGDTUIButtonConfiguration>> RuntimeButtonsConfiguration{};

private:
	UFUNCTION()
	void HandleButtonListClicked(const FName& ButtonId);

	void BuildButtonsList(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration);

	void RemoveButtonsBindings();
	
	UPROPERTY()
	TArray<TObjectPtr<UGDTUIUWButtonBase>> ButtonsList{};
};