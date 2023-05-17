#pragma once

#include "Engine/DataAsset.h"

#include "GDTUIButtonAudioConfiguration.generated.h"

class USoundBase;

UCLASS()
class GAMEDEVTOOLBOXUI_API UGDTUIButtonAudioConfiguration : public UDataAsset
{
    GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	TObjectPtr<USoundBase> OnClickSound{};
};