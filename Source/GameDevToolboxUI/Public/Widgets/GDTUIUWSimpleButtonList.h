#pragma once

#include "CoreMinimal.h"
#include "Widgets/GDTUIUserWidget.h"
#include "Interfaces/GDTUIFirstFocusInterface.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWSimpleButtonList.generated.h"

class UGDTUIUWButtonBase;
class UVerticalBox;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGDTUIButtonListClicked, const FName&, ButtonId);

UCLASS(BlueprintType, Blueprintable, ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Simple Button List", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWSimpleButtonList : public UGDTUIUserWidget
	, public IGDTUIFirstFocusInterface
{
	GENERATED_BODY()
public:

	// IGDTUIFirstFocusInterface
	virtual UWidget* GetFirstFocusWidget() const override;
	// ~ IGDTUIFirstFocusInterface

	void SetButtonsConfiguration(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration);

	FGDTUIButtonListClicked OnButtonListClickedDelegate{};

protected:
	// UUserWidget
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

#if WITH_EDITOR	
	virtual const FText GetPaletteCategory() override;
#endif // WITH_EDITOR

	UPROPERTY(EditInstanceOnly, Category = UI)
	TSubclassOf<UGDTUIUWButtonBase> ButtonClass{};
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UVerticalBox> ButtonsVerticalBoxContainer{};
	UPROPERTY(EditAnywhere, Category = UI)
	bool bSeparateButtonsWithSpacers = true;
	UPROPERTY(EditAnywhere, Category = UI, meta=(EditCondition="bSeparateButtonsWithSpacers"))
	FVector2D SpacerSize {0.0f, 32.0f};

private:
	UFUNCTION()
	void HandleButtonListClicked(const FName& ButtonId);

	void BuildButtonsList();

	UPROPERTY()
	TArray<TObjectPtr<UGDTUIUWButtonBase>> ButtonsList{};
	TArray<FGDTUIButtonConfiguration> ButtonsConfiguration{};
};