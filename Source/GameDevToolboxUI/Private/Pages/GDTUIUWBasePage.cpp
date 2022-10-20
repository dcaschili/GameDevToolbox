#include "Pages/GDTUIUWBasePage.h"

#include "Components/Widget.h"
#include "GDTUILogCategories.h"

void UGDTUIUWBasePage::NativeOnActivated()
{
	Super::NativeOnActivated();

	InnerOnActivated();

	InnerSetupFirstFocus();
}

void UGDTUIUWBasePage::NativeOnDeactivated()
{
	InnerOnDeactivated();

	Super::NativeOnDeactivated();
}

void UGDTUIUWBasePage::InnerSetupFirstFocus()
{
	UWidget* Widget = GetDesiredFocusTarget();
	if (Widget)
	{
		UE_LOG(GDTUILog, Log, TEXT("Setting focus on: %s"), *Widget->GetName());
		Widget->SetFocus();
	}
	else
	{
		UE_LOG(GDTUILog, Warning, TEXT("No widget to focus specified for widget: %s"), *GetName());
		ensure(false);
	}
}

