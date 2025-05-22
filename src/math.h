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
	void Damp(float factor, float minMagnitude, float deltaTime);
	float Magnitude() const;
	void Normalize();
	void NormalizeTo(const Vector3 *rhs);
	void NormalizeTo(const Vector3 *other, float magnitude);
	void PitchYaw(Vector3 *angles) const;
	float WeightedNormalize();
};

int FloorLog2(int value);
float GetAngleDelta(float base, float target);
int IsPrimeNumber(int value);
int NextPrimeNumber(int start);
float NormalizeAngle180(float angle);
float NormalizeAngle360(float angle);
float WeightedAverage(float a, float b, float c);
