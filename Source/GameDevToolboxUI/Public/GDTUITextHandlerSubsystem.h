#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GDTUITextHandlerSubsystem.generated.h"

class UDataTable;

UCLASS()
class GAMEDEVTOOLBOXUI_API UGDTUITextHandlerSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
	UGDTUITextHandlerSubsystem();

	const UDataTable* GetTextDataTable() const;

private:
	// Data table containing the mapping text id - text
	UPROPERTY()
	UDataTable* TextDataTable {};	
};