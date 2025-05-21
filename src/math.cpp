#include "math.h"
#include "typedefs.h"

#include <cmath>

// Win: 0047e9e0
void vector3::PitchYaw(vector3 *angles) const
{
	float fVar1;

	angles->z = 0.0f;
	fVar1 = std::asinf(z);
	angles->x = fVar1;
	fVar1 = std::atan2f(y, x);
	angles->y = fVar1;
	return;
}

// Win: 00501000
float NormalizeAngle180(float angle)
{
	undefined4 local_8;

	local_8 = NormalizeAngle360(angle);
	if (180.0f < local_8)
	{
		local_8 = -(360.0f - local_8);
	}
	return local_8;
}

// Win: 00500f40
float NormalizeAngle360(float angle)
{
	float fVar1;
	float local_c;

	if (0.0f <= angle)
	{
		if (angle < 360.0f)
		{
			return angle;
		}
		fVar1 = std::roundf(angle / 360.0f);
		local_c = angle - fVar1 * 360.0f;
	}
	else
	{
		local_c = -angle;
		if (360.0f <= local_c)
		{
			fVar1 = std::roundf(local_c / 360.0f);
			local_c = local_c - fVar1 * 360.0f;
		}
		local_c = 360.0f - local_c;
	}
	if (local_c == 360.0f)
	{
		local_c = 0.0f;
	}
	return local_c;
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

	if (0.0f <= a)
	{
		local_14 = a;
	}
	else
	{
		local_14 = -a;
	}
	if (0.0f <= b)
	{
		local_18 = b;
	}
	else
	{
		local_18 = -b;
	}
	if (0.0f <= c)
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
	return local_10 / 2.0f + local_8 / 2.0f + local_c;
}
