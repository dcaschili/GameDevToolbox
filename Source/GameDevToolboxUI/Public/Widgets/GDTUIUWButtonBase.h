#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Data/GDTUIButtonConfiguration.h"

#include "GDTUIUWButtonBase.generated.h"

class UGDTUITextBlockBase;

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDT Button Base", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWButtonBase : public UCommonButtonBase
{
    GENERATED_BODY()
public:
	void SetButtonConfiguration(const FGDTUIButtonConfiguration& InButtonConfiguration) { ButtonConfiguration = InButtonConfiguration; }

	FName GetButtonId() const { return ButtonConfiguration.ButtonId; }	

protected:
	virtual void NativeConstruct() override;

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