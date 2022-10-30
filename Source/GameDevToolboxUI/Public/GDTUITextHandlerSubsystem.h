#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GDTUITextHandlerSubsystem.generated.h"

class UDataTable;

/**
	This subsystem handles the custom textId-text translation system.
	It can be enabled from config and requires a data table to specify the mappings.
	It is used by the Utility function and the text blocks widgets.
*/
UCLASS(Abstract, Blueprintable)
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

	static bool IsEnabledFromConfig();

private:
	// Data table containing the mapping text id - text
	UPROPERTY(EditDefaultsOnly, Category="Configuration")
	UDataTable* TextDataTable {};	

	static const FString ConfigSection;
	static const FString ConfigName;
};