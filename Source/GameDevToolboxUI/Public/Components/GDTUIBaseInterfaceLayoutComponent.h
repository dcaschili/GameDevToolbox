#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GDTUIBaseInterfaceLayoutComponent.generated.h"

class UGDTUIUWBasePageLayout;
class UGDTUIUWBasePage;

/**
	Component that spawns and provides access to the base 
	layout for the UI.
	It must be used only on APlayerController classes or subclasses.
*/
UCLASS(Blueprintable, BlueprintType, ClassGroup = UI, EditInLineNew, meta = (BlueprintSpawnableComponent))
class GAMEDEVTOOLBOXUI_API UGDTUIBaseInterfaceLayoutComponent : public UActorComponent
{
    GENERATED_BODY()
public:
	UGDTUIBaseInterfaceLayoutComponent();

	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;

	UGDTUIUWBasePageLayout* GetLayout() { return BaseLayout; }

protected:
	APlayerController* GetOwnerPlayerController() const;

	UPROPERTY(EditDefaultsOnly, Category = "UI|Layout")
	TSubclassOf<UGDTUIUWBasePageLayout> BaseLayoutClass = nullptr;
	/** Whether the layout should be place on player screen or viewport.*/
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	bool bIsPlayerScreen = true;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UGDTUIUWBasePageLayout> BaseLayout{};
};