#include "math.h"
#include "typedefs.h"

#include <cmath>

// Win: 0047e9e0
void vector3::PitchYaw(vector3 *angles) const
{
	float fVar1;

	angles->z = 0.0;
	fVar1 = std::asinf(z);
	angles->x = fVar1;
	fVar1 = std::atan2f(y, x);
	angles->y = fVar1;
	return;
}

// Win: 00501a80
float WeightedAverage(float a, float b, float c)
{
	undefined4 local_1c;
	undefined4 local_18;
	undefined4 local_14;
	undefined4 local_10;
	undefined4 local_c;
	undefined4 local_8;

	if (0.0 <= a)
	{
		local_14 = a;
	}
	else
	{
		local_14 = -a;
	}
	if (0.0 <= b)
	{
		local_18 = b;
	}
	else
	{
		local_18 = -b;
	}
	if (0.0 <= c)
	{
		local_1c = c;
	}
	else
	{
		local_1c = -c;
	}
	if (local_14 <= local_18)
	{
		if (local_1c < local_18)
		{
			local_c = local_18;
			if (local_14 <= local_1c)
			{
				local_8 = local_1c;
				local_10 = local_14;
			}
			else
			{
				local_8 = local_14;
				local_10 = local_1c;
			}
		}
	}
	else if (local_1c < local_14)
	{
		local_c = local_14;
		if (local_18 <= local_1c)
		{
			local_8 = local_1c;
			local_10 = local_18;
		}
		else
		{
			local_8 = local_18;
			local_10 = local_1c;
		}
	}
	return local_10 / 2.0 + local_8 / 2.0 + local_c;
}
