#include "GDTUITextHandlerSubsystem.h"

#include "UObject/ConstructorHelpers.h"
#include "GDTUILogCategories.h"
#include "Misc/ConfigCacheIni.h"

const FString UGDTUITextHandlerSubsystem::ConfigName = TEXT("bTextHandlerSubsystemEnabled");
const FString UGDTUITextHandlerSubsystem::ConfigSection = TEXT("TextHandlerSubsystem");

bool UGDTUITextHandlerSubsystem::IsEnabledFromConfig()
{
	bool bEnabledFromConfig = false;
	GConfig->GetBool(*ConfigSection, *ConfigName, bEnabledFromConfig, GGameIni);

	return bEnabledFromConfig;
}

const UDataTable* UGDTUITextHandlerSubsystem::GetTextDataTable() const
{
	if (TextDataTable)
	{
		return TextDataTable;
	}
	else
	{
		UE_LOG(GDTUILog, Error, TEXT("Missing text data table. You should create and add the data table to the text handler subsystem!"));
		ensure(false);
		return nullptr;
	}  
}

void UGDTUITextHandlerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

bool UGDTUITextHandlerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return IsEnabledFromConfig();
}

void UGDTUITextHandlerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

