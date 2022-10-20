#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Interfaces/GDTUIRefreshableInterface.h"

#include "GDTUIUserWidget.generated.h"

UCLASS(ClassGroup = UI, meta = (Category = "GameDevToolboxUI", DisplayName = "GDTUI User Widget", PrioritizeCategories = "Content"))
class GAMEDEVTOOLBOXUI_API UGDTUIUserWidget : public UCommonUserWidget
    , public IGDTUIRefreshableInterface
{
    GENERATED_BODY()
public:

};