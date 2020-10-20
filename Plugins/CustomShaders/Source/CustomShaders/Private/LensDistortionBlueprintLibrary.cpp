// Copyright Epic Games, Inc. All Rights Reserved.

#include "LensDistortionBlueprintLibrary.h"



UCustomShadersBlueprintLibrary::UCustomShadersBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{ }


// static
void UCustomShadersBlueprintLibrary::GetUndistortOverscanFactor(
    const FCustomShadersCameraModel& CameraModel,
    float DistortedHorizontalFOV,
    float DistortedAspectRatio,
    float& UndistortOverscanFactor)
{
    UndistortOverscanFactor = CameraModel.GetUndistortOverscanFactor(DistortedHorizontalFOV, DistortedAspectRatio);
}


// static
void UCustomShadersBlueprintLibrary::DrawUVDisplacementToRenderTarget(
    const UObject* WorldContextObject,
    const FCustomShadersCameraModel& CameraModel,
    float DistortedHorizontalFOV,
    float DistortedAspectRatio,
    float UndistortOverscanFactor,
    class UTextureRenderTarget2D* OutputRenderTarget,
    float OutputMultiply,
    float OutputAdd)
{
    CameraModel.DrawUVDisplacementToRenderTarget(
        WorldContextObject->GetWorld(),
        DistortedHorizontalFOV, DistortedAspectRatio,
        UndistortOverscanFactor, OutputRenderTarget,
        OutputMultiply, OutputAdd);
}
