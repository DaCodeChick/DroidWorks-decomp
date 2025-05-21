#pragma once

struct Vector2
{
	float x, y;

	void Normalize();
};

struct Vector3
{
	float x, y, z;

	void Add(const Vector3 *rhs);
	float Magnitude() const;
	void Normalize();
	void NormalizeTo(const Vector3 *rhs);
	void NormalizeTo(const Vector3 *other, float magnitude);
	void PitchYaw(Vector3 *angles) const;
	float WeightedNormalize();
};

float GetAngleDelta(float base, float target);
float NormalizeAngle180(float angle);
float NormalizeAngle360(float angle);
float WeightedAverage(float a, float b, float c);
