#include "Pages/GDTUIUWBasePageLayout.h"

#include "Widgets/CommonActivatableWidgetContainer.h"
#include "GDTUILogCategories.h"

UCommonActivatableWidget* UGDTUIUWBasePageLayout::PushWidget(TSubclassOf<UGDTUIUWBaseActivatableWidget> InWidgetClass, EPageLayoutStackType InStackType)
{
	if (UCommonActivatableWidgetStack* Stack = GetWidgetStackByType(InStackType))
	{
		return Stack->AddWidget(InWidgetClass);
	}
	else
	{
		GDTUI_LOG(GDTUILog, Warning, TEXT("Can't find common activatable widget stack for type: %s"), *UEnum::GetValueAsString(InStackType));
		ensure(false);
		return nullptr;
	}
}

UCommonActivatableWidget* UGDTUIUWBasePageLayout::GetActiveWidget(EPageLayoutStackType InStackType) const
{
	if (UCommonActivatableWidgetStack* const Stack = GetWidgetStackByType(InStackType))
	{
		return Stack->GetActiveWidget();
	}
	else
	{
		GDTUI_LOG(GDTUILog, Warning, TEXT("Can't find common activatable widget stack for type: %s"), *UEnum::GetValueAsString(InStackType));
		ensure(false);
		return nullptr;
	}
}

void UGDTUIUWBasePageLayout::ClearLayoutStack(EPageLayoutStackType InStackType)
{
	if (UCommonActivatableWidgetStack* const Stack = GetWidgetStackByType(InStackType))
	{
		Stack->ClearWidgets();
	}
	else
	{
		GDTUI_LOG(GDTUILog, Warning, TEXT("Can't find common activatable widget stack for type: %s"), *UEnum::GetValueAsString(InStackType));
		ensure(false);
		return;
	}
}

UCommonActivatableWidgetStack* UGDTUIUWBasePageLayout::GetWidgetStackByType(EPageLayoutStackType InStackType) const
{
	UCommonActivatableWidgetStack* Stack{};
	switch (InStackType)
	{
	case EPageLayoutStackType::Main:
		Stack = MainStack;
		break;
	case EPageLayoutStackType::Popup:
		Stack = PopupStack;
		break;
	case EPageLayoutStackType::GameUI:
		Stack = GameUIStack;
		break;
	default:
		break;
	}

	return Stack;
}
