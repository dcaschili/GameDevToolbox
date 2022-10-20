#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWButtonBase.generated.h"

class UGDTUITextBlockBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGDTUIButtonBaseSelectedStateChanged, const FName&, ButtonId, bool, bSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGDTUIButtonBaseClicked, const FName&, ButtonId);

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Button Base", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWButtonBase : public UCommonButtonBase
{
    GENERATED_BODY()
public:
	void SetButtonConfiguration(const FGDTUIButtonConfiguration& InButtonConfiguration) { ButtonConfiguration = InButtonConfiguration; }

	FName GetButtonId() const { return ButtonConfiguration.ButtonId; }	

	FGDTUIButtonBaseClicked OnButtonBaseClickedDelegate{};

protected:
	virtual void NativeConstruct() override;
	
	// UCommonButtonBase
	virtual void NativeOnClicked() override;
	// ~UCommonButtonBase
	
	virtual void InnerApplyButtonConfiguration() {}

#if WITH_EDITOR	
	virtual const FText GetPaletteCategory() override;	
#endif // WITH_EDITOR
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Configuration")
	FGDTUIButtonConfiguration ButtonConfiguration{};

private:
	void ApplyButtonConfiguration();


	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UGDTUITextBlockBase> ButtonText{};
	
};