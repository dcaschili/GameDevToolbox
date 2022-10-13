#include "GDTUITextHandlerSubsystem.h"

#include "GDTUILogCategories.h"

UGDTUITextHandlerSubsystem::UGDTUITextHandlerSubsystem()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> LoadedTextDataTable(TEXT("/Game/Blueprints/DT_TextIdToTextTable"));
	TextDataTable = LoadedTextDataTable.Object;
}

const UDataTable* UGDTUITextHandlerSubsystem::GetTextDataTable() const
{
	if (TextDataTable)
	{
		return TextDataTable;
	}
	else
	{
		UE_LOG(GDTUILog, Error, TEXT("Missing text data table. You should initialize the UGDTUITextHandlerSubsystem to display text id values!"));
		ensure(false);
		return nullptr;
	}  
}

