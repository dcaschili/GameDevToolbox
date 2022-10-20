#pragma once

#include "CoreMinimal.h"

#include "GDTUIFirstFocusInterface.generated.h"

class UWidget;

UINTERFACE()
class GAMEDEVTOOLBOXUI_API UGDTUIFirstFocusInterface : public UInterface
{
    GENERATED_BODY()
};

class GAMEDEVTOOLBOXUI_API IGDTUIFirstFocusInterface
{
    GENERATED_BODY()
public:
    /**
     * @brief Get the First Focus Widget object
     * Get the widget that should be focused first. 
     * Return nullptr if no widget should be focused (default)
     * @return UWidget* 
     */
    virtual UWidget* GetFirstFocusWidget() const { return nullptr; }
};