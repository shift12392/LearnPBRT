

#include "Math.h"

bool URay::IntersectP(const FURay & InRay, const FBox& InBox, float * Hit0, float * Hit1)
{
	float T0 = 0; float T1 = InRay.TMax;

	for (int i = 0; i < 3; i++)
	{
		float InvRayDir = 1 / InRay.Ray.Direction[i];

		float TNear = (InBox.Min[i] - InRay.Ray.Origin[i]) * InvRayDir;
		float TFar = (InBox.Max[i] - InRay.Ray.Origin[i]) * InvRayDir;

		if (TNear > TFar)
			Swap(TNear, TFar);

		TFar *= 1 + 2 * Gamma(3);
		T0 = TNear > T0 ? TNear : T0;
		T1 = TFar < T1 ? TFar : T1;
		if (T0 > T1)
			return false;
	}

	if (Hit0 != nullptr)
	{
		*Hit0 = T0;
	}

	if (Hit1 != nullptr)
	{
		*Hit1 = T1;
	}
	return true;
}
