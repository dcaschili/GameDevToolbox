#include "Utils/GDTUITextFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "GDTUITextHandlerSubsystem.h"
#include "Data/GDTUITextRow.h"
#include "GDTUILogCategories.h"
#include "Engine/GameInstance.h"

FText UGDTUITextFunctionLibrary::GetTextById(const UObject* WorldContextObject, const FName& TextId)
{
	if (UGDTUITextHandlerSubsystem::IsEnabledFromConfig())
	{
		const UGameInstance* const GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
		const UGDTUITextHandlerSubsystem* const TextHandlerSubsystem = GameInstance ? GameInstance->GetSubsystem<UGDTUITextHandlerSubsystem>() : nullptr;

		if (TextHandlerSubsystem)
		{
			const UDataTable* TextByIdTable = TextHandlerSubsystem->GetTextDataTable();
			if (TextByIdTable)
			{
				static const FString ContextString(TEXT("Text By Text Id"));
				if (const FGDTUITextRow* TextRow = TextByIdTable->FindRow<FGDTUITextRow>(TextId, ContextString))
				{
					return FText::FromName(TextRow->Text);
				}
				else
				{
					UE_LOG(GDTUILog, Error, TEXT("Can't find id %s in text id data table: %s"), *TextId.ToString(), *TextByIdTable->GetName());
				}
			}
		}
		else
		{
			UE_LOG(GDTUILog, Error, TEXT("Can't find TextHandlerSubsystem. You should create a blueprint instance to specify the data table!"));
		}
	}
	else
	{
		UE_LOG(GDTUILog, Error, TEXT("Can't find TextHandlerSubsystem. You should enable the subsystem from config!"));
	}

	return FText();
}
