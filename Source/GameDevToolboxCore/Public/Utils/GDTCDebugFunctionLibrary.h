#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GDTCDebugFunctionLibrary.generated.h"

UCLASS()
class GAMEDEVTOOLBOXCORE_API UGDTCDebugFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static void DrawLineDebug(const UWorld* World, const FVector& LineStart, const FVector& LineDir, const FColor& Color = FColor::Green, float Length = LineLength);
	static void DrawBoxDebug(const UWorld* World, const FVector& Origin, const FVector& Extent, const FColor& Color = FColor::Green);
	static void DrawSphereDebug(const UWorld* World, const FVector& Center, const FColor& Color = FColor::Green);

private:
	static const float LineLength;
	static const float LineThickness;
	static const float BoxThickness;
	
	// Sphere
	static const float SphereRadius;
	static const float SphereThickness;
	static const int SphereSegments;

	static const float LifeTime;
};