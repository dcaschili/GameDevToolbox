#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GDTUITextHandlerSubsystem.generated.h"

class UDataTable;

/**
	This subsystem handles the custom textId-text translation system.
	It can be enabled from config and requires a data table to specify the mappings.
	It is used by the Utility function and the text blocks widgets.
	In order to use it, you should implement a blueprint version and provide the data table.
	The bluprint must be placed on the content folder no subdirectories.
*/
UCLASS(Config=Game)
class GAMEDEVTOOLBOXUI_API UGDTUITextHandlerSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
	const UDataTable* GetTextDataTable() const;

	// USubsystem
	virtual void Initialize(FSubsystemCollectionBase & Collection) override;
	virtual bool ShouldCreateSubsystem(UObject * Outer) const override;
	virtual void Deinitialize() override;
	// ~USubsystem

private:
	UPROPERTY(Config)
	bool bTextHandlerEnabledFromConfig = false;
	UPROPERTY(Config)
	FSoftObjectPath TextIdToTextDataTablePath{};

	UPROPERTY()
	TObjectPtr<UDataTable> TextDataTable{};
};