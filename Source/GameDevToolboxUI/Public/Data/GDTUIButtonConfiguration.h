#pragma once

#include "CoreMinimal.h"

#include "GDTUIButtonConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FGDTUIButtonConfiguration
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button Configuration")
    FName ButtonId{};
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button Configuration")
    FName ButtonText{};

};