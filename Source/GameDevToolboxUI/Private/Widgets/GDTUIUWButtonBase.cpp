#include "Widgets/GDTUIUWButtonBase.h"

#include "GDTUICategoryPaletteDefinitions.h"
#include "Widgets/GDTUITextBlockBase.h"
#include "GDTUILogCategories.h"
#include "Data/GDTUIButtonAudioConfiguration.h"
#include "Kismet/GameplayStatics.h"

void UGDTUIUWButtonBase::NativeConstruct()
{
	Super::NativeConstruct();
	ApplyButtonConfiguration();
}

void UGDTUIUWButtonBase::NativeOnClicked()
{
	Super::NativeOnClicked();
	
	if (ButtonAudioConfiguration && ButtonAudioConfiguration->OnClickSound)
	{
		// Play sound that persists level travel.
		UGameplayStatics::SpawnSound2D(this, ButtonAudioConfiguration->OnClickSound, 1.0f, 1.0f, 0.0f, nullptr, true, true);
	}

	GDTUI_SHORT_LOG(GDTUILog, VeryVerbose, TEXT("Button Clicked: %s"), *GetButtonId().ToString());
	OnButtonBaseClickedDelegate.Broadcast(ButtonConfiguration.ButtonId);

}

#if WITH_EDITOR	
const FText UGDTUIUWButtonBase::GetPaletteCategory()
{
    return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR

void UGDTUIUWButtonBase::ApplyButtonConfiguration()
{
	if (ButtonText)
	{
		ButtonText->SetContentText(ButtonConfiguration.ButtonText, ButtonConfiguration.bUseButtonTextAsTextId);
	}

	InnerApplyButtonConfiguration();
}