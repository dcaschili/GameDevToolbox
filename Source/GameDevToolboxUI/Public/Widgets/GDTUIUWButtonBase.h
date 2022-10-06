#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"

#include "GDTUIUWButtonBase.generated.h"

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDT Button Base", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUWButtonBase : public UCommonButtonBase
{
    GENERATED_BODY()

protected:

#if WITH_EDITOR	
	virtual const FText GetPaletteCategory() override;	
#endif // WITH_EDITOR
};