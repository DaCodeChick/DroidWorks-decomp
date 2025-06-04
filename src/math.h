#pragma once

/// @brief A 2D vector
struct Vector2
{
	float x; ///< The x-coordinate of the vector
	float y; ///< The y-coordinate of the vector

	/// @brief Normalizes the vector to a unit vector
	void Normalize();
};

/// @brief A 3D vector
struct Vector3
{
	float x; ///< The x-coordinate of the vector
	float y; ///< The y-coordinate of the vector
	float z; ///< The z-coordinate of the vector

	/**
	 * @brief Adds another vector to this vector.
	 * 
	 * @param rhs The vector to add.
	 */
	void Add(const Vector3 *rhs);

	/**
	 * @brief Damps the vector's movement over time.
	 * 
	 * @param factor The damping factor.
	 * @param minMagnitude The minimum magnitude before damping stops.
	 * @param deltaTime The time elapsed since the last update.
	 */
	void Damp(float factor, float minMagnitude, float deltaTime);
	
	/**
	 * @brief Calculates the magnitude (length) of the vector.
	 * 
	 * @return The magnitude of the vector.
	 */
	float Magnitude() const;

	/// @brief Normalizes the vector to a unit vector.
	void Normalize();

	/**
	 * @brief Normalizes the vector to a unit vector.
	 * 
	 * @param rhs The vector to normalize.
	 */
	void NormalizeTo(const Vector3 *rhs);

	/**
	 * @brief Normalizes the vector to a unit vector with a specified magnitude.
	 * 
	 * @param other The vector to normalize.
	 * @param magnitude The desired magnitude of the normalized vector.
	 */
	void NormalizeTo(const Vector3 *other, float magnitude);

	/**
	 * @brief Calculates the pitch and yaw angles from the vector.
	 * 
	 * @param angles The vector to store the pitch and yaw angles.
	 */
	void PitchYaw(Vector3 *angles) const;

	/**
	 * @brief Calculates the weighted normalization of the vector.
	 * 
	 * @return The weighted normalization factor.
	 */
	float WeightedNormalize();
};

/**
 * @brief Calculates the floor of the base 2 logarithm of a value.
 * 
 * @param value The value to calculate the logarithm for.
 * @return The floor of the base 2 logarithm.
 */
int FloorLog2(int value);

/**
 * @brief Calculates the angle delta between two angles.
 * 
 * @param base The base angle.
 * @param target The target angle.
 * @return The angle delta.
 */
float GetAngleDelta(float base, float target);

/**
 * @brief Checks if a number is prime.
 * 
 * @param value The number to check.
 * @return 1 if prime, 0 otherwise.
 */
int IsPrimeNumber(int value);

/**
 * @brief Finds the next prime number greater than or equal to a given start value.
 * 
 * @param start The starting value to check for primality.
 * @return The next prime number.
 */
int NextPrimeNumber(int start);

/**
 * @brief Normalizes an angle to the range of -180 to 180 degrees.
 * 
 * @param angle The angle to normalize.
 * @return The normalized angle.
 */
float NormalizeAngle180(float angle);

/**
 * @brief Normalizes an angle to the range of 0 to 360 degrees.
 * 
 * @param angle The angle to normalize.
 * @return The normalized angle.
 */
float NormalizeAngle360(float angle);

/**
 * @brief Calculates the weighted average of three float values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @param c The third value.
 * @return The weighted average of the three values.
 */
float WeightedAverage(float a, float b, float c);
