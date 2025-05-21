#pragma once

struct Vector3
{
	float x, y, z;

	void Normalize();
	void PitchYaw(Vector3 *angles) const;
};

float GetAngleDelta(float base, float target);
float NormalizeAngle180(float angle);
float NormalizeAngle360(float angle);
float WeightedAverage(float a, float b, float c);
