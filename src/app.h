#pragma once

#include "typedefs.h"

#ifdef _WIN32
typedef HINSTANCE AppHandle;
typedef HWND WindowHandle;
#endif

/**
 * @brief Get the application handle.
 * 
 * @return The handle to the application.
 */
AppHandle GetAppHandle();

/**
 * @brief Get the application window handle.
 * 
 * @return The handle to the application window.
 */
WindowHandle GetAppWindow();

/**
 * @brief Set the application handle.
 * 
 * @param handle The handle to set for the application.
 */
void SetAppHandle(AppHandle handle);

/**
 * @brief Set the application window handle.
 * 
 * @param handle The handle to set for the application window.
 * @return The window handle.
 */
WindowHandle SetAppWindow(WindowHandle handle);
