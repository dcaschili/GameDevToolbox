#pragma once

#include "CommonTextBlock.h"

#include "GDTUITextBlockBase.generated.h"


UENUM(BlueprintType)
enum class ETextCaseEnum : uint8
{
	kNormal		UMETA(DisplayName = "Normal"),
	kUppercase	UMETA(DisplayName = "Uppercase"),
	kLowercase	UMETA(DisplayName = "Lowercase")
};


/**

*/
UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI Text Block Base", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUITextBlockBase : public UCommonTextBlock
{
    GENERATED_BODY()
public:
	void SetContentText(const FName& InContent, bool bInUseContentAsTextId = false);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

#if WITH_EDITOR	
	virtual const FText GetPaletteCategory() override;	
#endif // WITH_EDITOR
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GDTUI|Text")
	FName ContentText {};
	/**
		If true, during construction, ContentText will be used as an id 
		to retrieve the text from the TextHandlerSubsystem.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GDTUI|Text")
	bool bUseContentAsTextId = true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GDTUI|Text")
	ETextCaseEnum TextCase = ETextCaseEnum::kNormal;

private:
	void UpdateText();
};