#include "GDTUITextHandlerSubsystem.h"

#include "GDTUILogCategories.h"
#include "Engine/DataTable.h"

const UDataTable* UGDTUITextHandlerSubsystem::GetTextDataTable() const
{
	if (TextDataTable)
	{
		return TextDataTable;
	}
	else
	{
		UE_LOG(GDTUILog, Error, TEXT("Missing text data table. You should setup the data table from Game.ini file"));
		ensure(false);
		return nullptr;
	}  
}

void UGDTUITextHandlerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (bTextHandlerEnabledFromConfig)
	{
		TextDataTable = Cast<UDataTable>(TextIdToTextDataTablePath.TryLoad());
		if (!TextDataTable)
		{
			UE_LOG(GDTUILog, Error, TEXT("Can't find TextId data table. Check the path you added to the Game .ini file!"));
			ensure(false);
		}
	}
}

bool UGDTUITextHandlerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return bTextHandlerEnabledFromConfig;
}

void UGDTUITextHandlerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

