#include "Widgets/GDTUIUWSimpleButtonList.h"

#include "Widgets/GDTUIUWButtonBase.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Spacer.h"
#include "Blueprint/WidgetTree.h"
#include "GDTUILogCategories.h"

void UGDTUIUWSimpleButtonList::SetButtonsConfiguration(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration)
{
	RuntimeButtonsConfiguration = InButtonsConfiguration;
	BuildButtonsList(RuntimeButtonsConfiguration.GetValue());
}

UWidget* UGDTUIUWSimpleButtonList::NativeGetDesiredFocusTarget() const
{
	if (ButtonsList.Num() > 0)
	{
		return ButtonsList[0];
	}
	return nullptr;
}

void UGDTUIUWSimpleButtonList::HandleButtonListClicked(const FName& ButtonId)
{
	UE_LOG(GDTUILog, Verbose, TEXT("List button Clicked: %s"), *ButtonId.ToString());	
	OnButtonListClickedDelegate.Broadcast(ButtonId);
}

void UGDTUIUWSimpleButtonList::BuildButtonsList(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration)
{
	ensure(ButtonsVerticalBoxContainer);

	TSubclassOf<UCommonButtonBase> TmpGameButtonClass = ButtonClass;
	if (!TmpGameButtonClass)
	{
		UE_LOG(GDTUILog, Warning, TEXT("Missing list button class! Using default class."));
		ensure(false);
		TmpGameButtonClass = UGDTUIUWButtonBase::StaticClass();
	}

	// Init buttons and register to callbacks.
	if (ButtonsVerticalBoxContainer)
	{
		RemoveButtonsBindings();

		ButtonsList.Empty();
		ButtonsVerticalBoxContainer->ClearChildren();

		for (const FGDTUIButtonConfiguration& ButtonConfig : InButtonsConfiguration)
		{
			UGDTUIUWButtonBase* Button = CreateWidget<UGDTUIUWButtonBase>(this, TmpGameButtonClass);
			if (ensure(Button))
			{
				Button->SetButtonConfiguration(ButtonConfig);
				Button->OnButtonBaseClickedDelegate.AddUniqueDynamic(this, &ThisClass::HandleButtonListClicked);
				
				ButtonsList.Add(Button);
				if (UVerticalBoxSlot* VerticalBoxSlot = ButtonsVerticalBoxContainer->AddChildToVerticalBox(Button))
				{
					FSlateChildSize ChildSize{};
					ChildSize.SizeRule = ESlateSizeRule::Automatic;
					ChildSize.Value = 1.0f;
					VerticalBoxSlot->SetSize(ChildSize);
				}
			}

			if (bSeparateButtonsWithSpacers && WidgetTree)
			{
				USpacer* Spacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
				if (Spacer)
				{
					Spacer->SetSize(SpacerSize);
					if (UVerticalBoxSlot* VerticalBoxSlot = ButtonsVerticalBoxContainer->AddChildToVerticalBox(Spacer))
					{
						FSlateChildSize ChildSize{};
						ChildSize.SizeRule = ESlateSizeRule::Automatic;
						ChildSize.Value = 1.0f;
						VerticalBoxSlot->SetSize(ChildSize);
					}
				}
			}
		}
	}
}

void UGDTUIUWSimpleButtonList::RemoveButtonsBindings()
{
	for (UGDTUIUWButtonBase* Button : ButtonsList)
	{
		if (Button)
		{
			Button->OnButtonBaseClickedDelegate.RemoveDynamic(this, &ThisClass::HandleButtonListClicked);
		}
	}
}

void UGDTUIUWSimpleButtonList::InnerOnActivated()
{
	Super::InnerOnActivated();
	
	if (RuntimeButtonsConfiguration.IsSet())
	{
		BuildButtonsList(RuntimeButtonsConfiguration.GetValue());
	}
	else
	{
		BuildButtonsList(DefaultButtonsConfiguration);
	}
}

void UGDTUIUWSimpleButtonList::InnerOnDeactivated()
{
	RemoveButtonsBindings();
	RuntimeButtonsConfiguration.Reset();

	Super::InnerOnDeactivated();
}

