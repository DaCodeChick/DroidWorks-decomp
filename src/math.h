#pragma once

struct vector3
{
	float x, y, z;

	void PitchYaw(vector3 *angles) const;
};

float NormalizeAngle(float angle);
float WeightedAverage(float a, float b, float c);
