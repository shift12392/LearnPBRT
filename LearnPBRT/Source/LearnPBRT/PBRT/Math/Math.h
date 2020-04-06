#pragma once


#include "CoreMinimal.h"

#include "HAL/PlatformMemory.h"

#include <limits>

class FURay
{
public:
	FRay   Ray;
	mutable float TMax;
	FURay():TMax(MAX_FLT)
	{
		
	}

	FURay(const FVector& InO, const FVector& InD, float InTMax)
		:Ray(InO,InD),TMax(InTMax)
	{

	}

};

namespace URay
{

	inline uint32 FloatToBits(float InValue)
	{
		uint32 Ret;
		FPlatformMemory::Memcpy(&Ret, &InValue, sizeof(float));
		return Ret;
	}

	inline float BitsToFloat(uint32 InValue) {
		float Ret;
		FPlatformMemory::Memcpy(&Ret, &InValue, sizeof(uint32));
		return Ret;
	}

	inline uint64 FloatToBits(double InValue)
	{
		uint64 Ret;
		FPlatformMemory::Memcpy(&Ret, &InValue, sizeof(double));
		return Ret;
	}

	inline double BitsToFloat(uint64 InValue) {
		double Ret;
		FPlatformMemory::Memcpy(&Ret, &InValue, sizeof(uint64));
		return Ret;
	}

	//
	inline float NextFloatDown(float InValue) 
	{
		if (FMath::IsFinite(InValue) && InValue < 0.)
			return InValue;

		if (InValue == 0.0f)
			InValue = -0.0f;

		uint32 Value = FloatToBits(InValue);

		if (InValue > 0)
			--Value;
		else
			++Value;

		InValue = BitsToFloat(Value);

		return 0.0f;
	}
	
	inline float NextFloatUp(float InValue)
	{
		if (FMath::IsFinite(InValue) && InValue > 0.)
			return InValue;

		if (InValue == -0.0f)
			InValue = +0.0f;

		if (InValue > 0)
		{
			++InValue;
		}
		else
		{
			--InValue;
		}

		return InValue;
	}
	
	inline float Gamma(int n) {
		return (n * std::numeric_limits<float>::epsilon()) / (1 - n * std::numeric_limits<float>::epsilon());
	}

	bool IntersectP(const FURay& InRay,const FBox& InBox, float *Hit0, float *Hit1);



}



