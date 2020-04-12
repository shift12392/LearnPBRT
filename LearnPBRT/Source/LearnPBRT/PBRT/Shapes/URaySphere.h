// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shape.h"
#include "../Math/EFloat.h"

/**
 * 
 */
class LEARNPBRT_API FURaySphere : public FShape
{
private:
	const float Radius;
	const float ZMin, ZMax;
	const float ThetaMin, ThetaMax, PhiMax;

public:
	FURaySphere(float InRadius,float InZMin,float InZMax,float InPhiMax)
		:Radius(InRadius)
		,ZMin(FMath::Clamp( FMath::Min(InZMin,InZMax),-Radius,Radius))
		,ZMax(FMath::Clamp(FMath::Max(InZMin,InZMax),-Radius,Radius))
		,ThetaMin(FMath::Acos(FMath::Clamp(ZMin/Radius,-1.0f,1.0f)))
		,ThetaMax(FMath::Acos(FMath::Clamp(ZMax/Radius,-1.0f,1.0f)))
		,PhiMax(FMath::Clamp(InPhiMax,0.0f,360.0f))
	{

	}


	virtual bool Intersect(const FURay &Ray, float *THit, FSurfaceInteraction *Isect, bool TestAlphaTexture = true) const
	{
		URay::EFloat  tt(1.0f);
		return true;
	}
};
