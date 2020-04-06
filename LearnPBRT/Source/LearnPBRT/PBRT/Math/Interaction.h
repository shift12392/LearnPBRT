// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct LEARNPBRT_API FInteraction
{
	FVector Point;
	FVector Normal;
	FVector W0;
	FVector Error;
	float Time;

	FInteraction(const FVector& InPoint,const FVector& InNormal,const FVector& InW0,
	    const FVector& InError,float InTime)
		:Point(InPoint),Normal(InNormal),W0(InW0),Error(InError),Time(InTime)
	{

	}

	bool IsSurfaceInteraction() const {
		return Normal == FVector::ZeroVector;
	}

};


struct LEARNPBRT_API FSurfaceInteraction : public FInteraction
{
	struct FShading
	{
		FVector Normal;
		FVector DPDV, DPDU;
		FVector DNDV, DNDU;
	};

	FVector2D UV;
	FVector DPDU, DPDV;
	FVector DNDU, DNDV;
	FShading Shading;


	FSurfaceInteraction(const FVector& InPoint, const FVector &InError, const FVector2D &InUV,
		const FVector& InW0, const FVector& InDPDU, const FVector& InDPDV, const FVector& InDNDU,
		const FVector& InDNDV, float InTime)
		:FInteraction(InPoint, (InDPDU ^ InDPDV).GetSafeNormal(),InW0,InError, InTime)
		,UV(InUV),DPDU(InDPDU),DPDV(InDPDV),DNDU(InDNDU),DNDV(InDNDV)
	{
		Shading.Normal = Normal;
		Shading.DPDU = DPDU;
		Shading.DPDV = DPDV;
		Shading.DNDU = DNDU;
		Shading.DNDV = DNDV;
	}
};
