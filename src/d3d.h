#pragma once

#include "typedefs.h"

/// @brief Cleanup the DirectDraw subsystem
void CleanupDirectDraw();

/// @brief Cleanup the Direct Sound subsystem
void CleanupDirectSound();

/**
 * @brief Set the Direct Sound Volume
 *
 * @param value The volume level to set, typically in the range of 0.0 (mute) to 1.0 (full volume).
 */
void SetDirectSoundVolume(float value);
