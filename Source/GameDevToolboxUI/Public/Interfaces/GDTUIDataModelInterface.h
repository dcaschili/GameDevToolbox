#pragma once

#include "Data/GDTUIDataModel.h"
#include "GDTUIDataModelInterface.generated.h"

class UGDTUIDataModel;

UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class GAMEDEVTOOLBOXUI_API UGDTUIDataModelInterface : public UInterface
{
    GENERATED_BODY()
};

class GAMEDEVTOOLBOXUI_API IGDTUIDataModelInterface
{
    GENERATED_BODY()
public:

    virtual void SetDataModel(UGDTUIDataModel* InModel) = 0;
    
    UFUNCTION(BlueprintCallable)
    virtual const UGDTUIDataModel* GetDataModel() const PURE_VIRTUAL(IGameDataModelUserInterface::GetDataModel, return nullptr;);
};