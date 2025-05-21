#pragma once

struct vector3
{
	float x, y, z;

	void PitchYaw(vector3 *angles) const;
};

float GetAngleDelta(float base, float target);
float NormalizeAngle180(float angle);
float NormalizeAngle360(float angle);
float WeightedAverage(float a, float b, float c);
