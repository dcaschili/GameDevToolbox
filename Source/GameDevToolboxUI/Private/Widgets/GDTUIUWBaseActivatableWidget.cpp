#include "Widgets/GDTUIUWBaseActivatableWidget.h"

void UGDTUIUWBaseActivatableWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	InnerOnActivated();

	InnerSetupFirstFocus();
}

void UGDTUIUWBaseActivatableWidget::NativeOnDeactivated()
{
	InnerOnDeactivated();

	Super::NativeOnDeactivated();
}
