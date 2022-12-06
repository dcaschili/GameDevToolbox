#include "Utils/GDTCDebugFunctionLibrary.h"

#include "Engine/World.h"

#if !UE_BUILD_SHIPPING
#include "DrawDebugHelpers.h"
#endif // !UE_BUILD_SHIPPING

const float UGDTCDebugFunctionLibrary::LineLength = 500.0f;
const float UGDTCDebugFunctionLibrary::LineThickness = 15.0f;
const float UGDTCDebugFunctionLibrary::BoxThickness = 50.0f;

const float UGDTCDebugFunctionLibrary::SphereRadius = 100.0f;
const float UGDTCDebugFunctionLibrary::SphereThickness = 15.0f;
const int UGDTCDebugFunctionLibrary::SphereSegments = 36;

const float UGDTCDebugFunctionLibrary::LifeTime = 5.0f;

void UGDTCDebugFunctionLibrary::DrawLineDebug(const UWorld* World, const FVector& LineStart, const FVector& LineDir, const FColor& Color, float Length)
{
#if !UE_BUILD_SHIPPING
	FVector EndPos = LineStart + LineDir * Length;

	DrawDebugLine(World, LineStart, EndPos, Color, false, LifeTime, 0, LineThickness);
#endif // !UE_BUILD_SHIPPING
}

void UGDTCDebugFunctionLibrary::DrawBoxDebug(const UWorld* World, const FVector& Origin, const FVector& Extent, const FColor& Color)
{
#if !UE_BUILD_SHIPPING
	DrawDebugBox(World, Origin, Extent, Color, false, -1.0f, 0, BoxThickness);
#endif // !UE_BUILD_SHIPPING
}

void UGDTCDebugFunctionLibrary::DrawSphereDebug(const UWorld* World, const FVector& Center, const FColor& Color)
{
#if !UE_BUILD_SHIPPING
	DrawDebugSphere(World, Center, SphereRadius, SphereSegments, Color, false, -1.0f, 0, SphereThickness);
#endif // !UE_BUILD_SHIPPING
}
