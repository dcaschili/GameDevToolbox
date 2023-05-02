#include "Pages/GDTUIUWSimpleButtonListPage.h"

#include "Widgets/GDTUIUWSimpleButtonList.h"
#include "Interfaces/GDTUIFirstFocusInterface.h"
#include "GDTUILogCategories.h"

UWidget* UGDTUIUWSimpleButtonListPage::NativeGetDesiredFocusTarget() const
{
	if (ButtonList)
	{
		return ButtonList->GetDesiredFocusTarget();
	}
	return Super::NativeGetDesiredFocusTarget();
}

void UGDTUIUWSimpleButtonListPage::InnerOnActivated()
{
	Super::InnerOnActivated();

	if (ButtonList)
	{
		ButtonList->OnButtonListClickedDelegate.AddUniqueDynamic(this, &ThisClass::HandleButtonClicked);
		ButtonList->ActivateWidget();
	}

	Execute_RefreshUI(this);
}

void UGDTUIUWSimpleButtonListPage::InnerOnDeactivated()
{
	if (ButtonList)
	{
		ButtonList->OnButtonListClickedDelegate.RemoveDynamic(this, &ThisClass::HandleButtonClicked);
		ButtonList->DeactivateWidget();
	}

	Super::InnerOnDeactivated();
}

void UGDTUIUWSimpleButtonListPage::HandleButtonClicked(const FName& ButtonId)
{
	UE_LOG(GDTUILog, VeryVerbose, TEXT("Clicked button: %s on page: %s"), *ButtonId.ToString(), *GetName());
	InnerHandleButtonClicked(ButtonId);

	OnButtonClicked.Broadcast(ButtonId);
}
