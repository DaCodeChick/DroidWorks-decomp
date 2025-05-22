#pragma once

#include "typedefs.h"

#ifdef _WIN32
typedef HINSTANCE AppHandle;
typedef HWND WindowHandle;
#endif

AppHandle GetAppHandle();
WindowHandle GetAppWindow();
void SetAppHandle(AppHandle handle);
WindowHandle SetAppWindow(WindowHandle handle);
