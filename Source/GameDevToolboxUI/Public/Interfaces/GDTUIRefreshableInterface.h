#pragma once

#include "CoreMinimal.h"

#include "GDTUIRefreshableInterface.generated.h"

UINTERFACE()
class GAMEDEVTOOLBOXUI_API UGDTUIRefreshableInterface : public UInterface
{
    GENERATED_BODY()
};

class GAMEDEVTOOLBOXUI_API IGDTUIRefreshableInterface
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintImplementableEvent, Category="UI")
    void RefreshUI();
};