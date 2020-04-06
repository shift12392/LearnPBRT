// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Math/Math.h"
#include "../Math/Interaction.h"

/**
 * 
 */
class LEARNPBRT_API FShape
{
public:
	FShape()
	{

	}

	FTransform LocalToWorld;
	FBox       LocalBox;


	FBox WorldBox() const 
	{
		FBox Ret;
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Min.X, LocalBox.Min.Y, LocalBox.Min.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Min.X, LocalBox.Max.Y, LocalBox.Min.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Max.X, LocalBox.Max.Y, LocalBox.Min.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Max.X, LocalBox.Min.Y, LocalBox.Min.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Min.X, LocalBox.Min.Y, LocalBox.Max.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Min.X, LocalBox.Max.Y, LocalBox.Max.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Max.X, LocalBox.Max.Y, LocalBox.Max.Z));
		Ret += LocalToWorld.TransformPosition(FVector(LocalBox.Max.X, LocalBox.Min.Y, LocalBox.Max.Z));
		return Ret;
	}

	virtual bool Intersect(const FURay &Ray, float *THit, FSurfaceInteraction *Isect, bool TestAlphaTexture = true) const = 0;

	virtual bool IntersectP(const FURay& Ray, bool TestAlphaTexture = true)
	{
		return Intersect(Ray, nullptr, nullptr, TestAlphaTexture);
	}

	//±íÃæ»ý
	virtual float Area() const = 0;
};
