#include "Widgets/GDTUIUWSimpleButtonList.h"

#include "Widgets/GDTUIUWButtonBase.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Spacer.h"
#include "Blueprint/WidgetTree.h"
#include "GDTUILogCategories.h"
#include "GDTUICategoryPaletteDefinitions.h"

UWidget* UGDTUIUWSimpleButtonList::GetFirstFocusWidget() const
{
	if (ButtonsList.Num() > 0)
	{
		return ButtonsList[0];
	}
	return nullptr;
}

void UGDTUIUWSimpleButtonList::SetButtonsConfiguration(const TArray<FGDTUIButtonConfiguration>& InButtonsConfiguration)
{
	ButtonsConfiguration = InButtonsConfiguration;
	BuildButtonsList();
}

void UGDTUIUWSimpleButtonList::HandleButtonListClicked(const FName& ButtonId)
{
	UE_LOG(GDTUILog, Verbose, TEXT("List button Clicked: %s"), *ButtonId.ToString());	
	OnButtonListClickedDelegate.Broadcast(ButtonId);
}

void UGDTUIUWSimpleButtonList::BuildButtonsList()
{
	ensure(ButtonsVerticalBoxContainer);

	TSubclassOf<UGDTUIUWButtonBase> TmpGameButtonClass = ButtonClass;
	if (!TmpGameButtonClass)
	{
		TmpGameButtonClass = UGDTUIUWButtonBase::StaticClass();
	}

	// Init buttons and register to callbacks.
	if (ButtonsVerticalBoxContainer)
	{
		ButtonsVerticalBoxContainer->ClearChildren();

		for (const FGDTUIButtonConfiguration& ButtonConfig : ButtonsConfiguration)
		{
			UGDTUIUWButtonBase* Button = CreateWidget<UGDTUIUWButtonBase>(this, TmpGameButtonClass);
			if (Button)
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
					Spacer->Size = SpacerSize;
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

void UGDTUIUWSimpleButtonList::NativeConstruct()
{
	BuildButtonsList();

	Super::NativeConstruct();
}

void UGDTUIUWSimpleButtonList::NativeDestruct()
{
	for (UGDTUIUWButtonBase* GameButton : ButtonsList)
	{
		if (GameButton)
		{
			GameButton->OnButtonBaseClickedDelegate.RemoveDynamic(this, &ThisClass::HandleButtonListClicked);
		}
	}

	Super::NativeDestruct();
}

#if WITH_EDITOR
const FText UGDTUIUWSimpleButtonList::GetPaletteCategory()
{
	return GDTUICategoryPaletteDefinitions::Default;
}
#endif

