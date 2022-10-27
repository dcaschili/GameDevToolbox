#include "Utils/GDTUICoreFunctionLibrary.h"

#include "Pages/GDTUIUWBasePageLayout.h"
#include "Kismet/GameplayStatics.h"
#include "Components/GDTUIBaseInterfaceLayoutComponent.h"
#include "GDTUILogCategories.h"

UGDTUIUWBasePageLayout* UGDTUICoreFunctionLibrary::GetPlayerBaseUILayout(const UObject* const InWorldContextObject, const int32 InPlayerIndex /*= 0*/)
{
	if (ensure(InPlayerIndex >= 0))
	{
		if (const APlayerController* PC = UGameplayStatics::GetPlayerController(InWorldContextObject, InPlayerIndex))
		{
			UGDTUIBaseInterfaceLayoutComponent* Component = Cast<UGDTUIBaseInterfaceLayoutComponent>(PC->GetComponentByClass(UGDTUIBaseInterfaceLayoutComponent::StaticClass()));
			if (!Component)
			{
				UE_LOG(GDTUILog, Warning, TEXT("Can't find base interface layout component for player: %d"), InPlayerIndex);
				return nullptr;
			}

			return Component->GetLayout();
		}
		else
		{
			UE_LOG(GDTUILog, Warning, TEXT("Can't find player controller for index: %d"), InPlayerIndex);
			ensure(false);
			return nullptr;
		}

	}
	else
	{
		UE_LOG(GDTUILog, Error, TEXT("Negative player index requested!"));
		ensure(false);
		return nullptr;
	}

}
