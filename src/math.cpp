#include "math.h"
#include "typedefs.h"

#include <cmath>

// Win: 0047e710
void Vector2::Normalize()
{
	float fVar1;

	fVar1 = std::sqrtf(x * x + y * y);
	if (fVar1 != 0.0f)
	{
		x = x / fVar1;
		y = y / fVar1;
	}
	return;
}

// Win: 0047e620
void Vector3::Add(const Vector3 *rhs)
{
	x = rhs->x + x;
	y = rhs->y + y;
	z = rhs->z + z;
	return;
}

// Win: 0047e650
float Vector3::Magnitude() const
{
	return std::sqrtf(x * x + z * z + y * y);
}

// Win: 0047e750
void Vector3::Normalize()
{
	float fVar1;

	fVar1 = std::sqrtf(x * x + z * z + y * y);
	if (fVar1 != 0.0f)
	{
		fVar1 = 1.0f / fVar1;
		x = x * fVar1;
		y = y * fVar1;
		z = z * fVar1;
	}
	return;
}

// Win: 0047e690
void Vector3::NormalizeTo(const Vector3 *rhs)
{
	float fVar1;

	fVar1 = std::sqrtf(rhs->x * rhs->x + rhs->z * rhs->z + rhs->y * rhs->y);
	if (fVar1 != 0.0f)
	{
		x = rhs->x / fVar1;
		y = rhs->y / fVar1;
		z = rhs->z / fVar1;
		return;
	}
	x = rhs->x;
	y = rhs->y;
	z = rhs->z;
	return;
}

// Win: 0047e950
void Vector3::NormalizeTo(const Vector3 *other, float magnitude)
{
	float fVar1;

	fVar1 = 1.0f / magnitude;
	x = other->x * fVar1;
	y = other->y * fVar1;
	z = other->z * fVar1;
	return;
}

// Win: 0047e9e0
void Vector3::PitchYaw(Vector3 *angles) const
{
	float fVar1;

	angles->z = 0.0f;
	fVar1 = std::asinf(z);
	angles->x = fVar1;
	fVar1 = std::atan2f(y, x);
	angles->y = fVar1;
	return;
}

// Win: 0047e7c0
float Vector3::WeightedNormalize()
{
	float fVar1;
	float local_28;
	float local_24;
	float local_20;
	float local_1c;
	float local_c;
	float local_8;

	if (0.0f <= x)
	{
		local_20 = x;
	}
	else
	{
		local_20 = -x;
	}
	local_c = local_20;
	if (0.0f <= y)
	{
		local_24 = y;
	}
	else
	{
		local_24 = -y;
	}
	local_8 = local_24;
	if (0.0f <= z)
	{
		local_28 = z;
	}
	else
	{
		local_28 = -z;
	}
	local_1c = local_28;
	if (local_28 <= local_24)
	{
		if (local_20 < local_24)
		{
			local_8 = local_20;
			local_c = local_24;
			if (local_20 < local_28)
			{
				local_1c = local_20;
				local_8 = local_28;
			}
		}
	}
	else if (local_28 <= local_20)
	{
		local_1c = local_24;
		local_8 = local_28;
	}
	else
	{
		local_1c = local_20;
		local_c = local_28;
		if (local_24 < local_20)
		{
			local_1c = local_24;
			local_8 = local_20;
		}
	}
	local_c = local_1c * 0.25f + local_8 * 0.34375f + local_c;
	fVar1 = 1.0f / local_c;
	x = x * fVar1;
	y = y * fVar1;
	z = z * fVar1;
	return local_c;
}

// Win: 004fd160
int FloorLog2(int value)
{
	int iVar1;

	iVar1 = 0;
	if (1 < value)
	{
		do
		{
			value = value >> 1;
			iVar1 = iVar1 + 1;
		} while (1 < value);
	}
	return iVar1;
}

// Win: 00501040
float GetAngleDelta(float base, float target)
{
	float fVar1;
	float fVar2;

	fVar1 = NormalizeAngle360(target);
	fVar2 = NormalizeAngle360(base);
	fVar1 = fVar1 - fVar2;
	if (0.0f <= fVar1)
	{
		if (180.0f < fVar1)
		{
			fVar1 = -(360.0f - fVar1);
		}
	}
	else if (fVar1 < -180.0f)
	{
		fVar1 = fVar1 + 360.0f;
	}
	return fVar1;
}

// Win: 00501cc0
int IsPrimeNumber(int value)
{
	int iVar1;

	iVar1 = 2;
	if (value + -1 < 3)
	{
		return 1;
	}
	do
	{
		if (value % iVar1 == 0)
		{
			return 0;
		}
		iVar1 = iVar1 + 1;
	} while (iVar1 < value + -1);
	return 1;
}

// Win: 00501c90
int NextPrimeNumber(int start)
{
	int iVar1;

	iVar1 = IsPrimeNumber(start);
	while (iVar1 == 0)
	{
		start = start + 1;
		iVar1 = IsPrimeNumber(start);
	}
	return start;
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
