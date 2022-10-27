#include "Components/GDTUIBaseInterfaceLayoutComponent.h"

#include "Pages/GDTUIUWBasePageLayout.h"

#if WITH_EDITOR
#include "GameFramework/PlayerController.h"
#endif // !WITH_EDITOR

UGDTUIBaseInterfaceLayoutComponent::UGDTUIBaseInterfaceLayoutComponent()
{
	bWantsInitializeComponent = true;
}

void UGDTUIBaseInterfaceLayoutComponent::InitializeComponent()
{
	Super::InitializeComponent();

#if WITH_EDITOR
	checkf(GetOwnerPlayerController(), TEXT("This component must be used only with player controller."));
#endif // !WITH_EDITOR

}

void UGDTUIBaseInterfaceLayoutComponent::BeginPlay()
{
	Super::BeginPlay();

	check(BaseLayoutClass);

	// Create base layout page
	BaseLayout = CreateWidget<UGDTUIUWBasePageLayout>(GetOwnerPlayerController(), BaseLayoutClass);
	if (BaseLayout)
	{
		if (bIsPlayerScreen)
		{
			BaseLayout->AddToPlayerScreen();
		}
		else
		{
			BaseLayout->AddToViewport();
		}
	}

}

APlayerController* UGDTUIBaseInterfaceLayoutComponent::GetOwnerPlayerController() const
{
	return Cast<APlayerController>(GetOwner());
}

