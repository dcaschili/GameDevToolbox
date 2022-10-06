#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GDTUITextFunctionLibrary.generated.h"

UCLASS()
class GAMEDEVTOOLBOXUI_API UGDTUITextFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    /**
     * Convert a text id to its corresponding text value.
    */
    UFUNCTION(BlueprintCallable, Category = "UI")
    static FText GetTextById(const UObject* WorldContextObject, const FName& TextId);
};