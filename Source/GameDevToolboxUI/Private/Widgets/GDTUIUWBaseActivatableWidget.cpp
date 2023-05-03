#include "Widgets/GDTUIUWBaseActivatableWidget.h"

void UGDTUIUWBaseActivatableWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	InnerOnActivated();
	
	if (bNeedFirstFocusSetup)
	{
		InnerSetupFirstFocus();
	}
}

void UGDTUIUWBaseActivatableWidget::NativeOnDeactivated()
{
	InnerOnDeactivated();

	Super::NativeOnDeactivated();
}

