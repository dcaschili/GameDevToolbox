#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GDTUICoreFunctionLibrary.generated.h"

class UGDTUIUWBasePageLayout;

UCLASS()
class GAMEDEVTOOLBOXUI_API UGDTUICoreFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:

    UFUNCTION(BlueprintCallable, Category = "GDT|UI|Layout")
    static UGDTUIUWBasePageLayout* GetPlayerBaseUILayout(const UObject* const InWorldContextObject, const int32 InPlayerIndex = 0);
};