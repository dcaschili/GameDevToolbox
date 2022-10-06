#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "GDTUITextRow.generated.h"

USTRUCT(BlueprintType)
struct GAMEDEVTOOLBOXUI_API FGDTUITextRow : public FTableRowBase
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TextId {};
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Text{};
};