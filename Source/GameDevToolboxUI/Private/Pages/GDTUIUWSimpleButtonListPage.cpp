#include "Pages/GDTUIUWSimpleButtonListPage.h"

#include "Widgets/GDTUIUWSimpleButtonList.h"
#include "Interfaces/GDTUIFirstFocusInterface.h"
#include "GDTUILogCategories.h"

UWidget* UGDTUIUWSimpleButtonListPage::NativeGetDesiredFocusTarget() const
{
	if (IGDTUIFirstFocusInterface* FirstFocusObject = Cast<IGDTUIFirstFocusInterface>(ButtonList))
	{
		return FirstFocusObject->GetFirstFocusWidget();
	}

	return Super::NativeGetDesiredFocusTarget();
}

void UGDTUIUWSimpleButtonListPage::InnerOnActivated()
{
	Super::InnerOnActivated();

	if (ButtonList)
	{
		ButtonList->OnButtonListClickedDelegate.AddUniqueDynamic(this, &ThisClass::HandleButtonClicked);
		ButtonList->SetButtonsConfiguration(ButtonsConfiguration);
	}

	Execute_RefreshUI(this);
}

void UGDTUIUWSimpleButtonListPage::InnerOnDeactivated()
{
	if (ButtonList)
	{
		ButtonList->OnButtonListClickedDelegate.RemoveDynamic(this, &ThisClass::HandleButtonClicked);
	}

	Super::InnerOnDeactivated();
}

void UGDTUIUWSimpleButtonListPage::HandleButtonClicked(const FName& ButtonId)
{
	UE_LOG(GDTUILog, VeryVerbose, TEXT("Clicked button: %s on page: %s"), *ButtonId.ToString(), *GetName());
	InnerHandleButtonClicked(ButtonId);
}
