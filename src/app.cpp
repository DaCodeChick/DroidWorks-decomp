#include "app.h"

// Win: 006479c4
static AppHandle gAppHandle = NULL;

// Win: 006479c0
static WindowHandle gAppWindow = NULL;

// Win: 00502fb0
AppHandle GetAppHandle(void)
{
	return gAppHandle;
}

// Win: 00502f90
WindowHandle GetAppWindow(void)
{
	return gAppWindow;
}

// Win: 00502fa0
void SetAppHandle(AppHandle handle)
{
	gAppHandle = handle;
	return;
}

// Win: 00502f80
WindowHandle SetAppWindow(WindowHandle handle)
{
	gAppWindow = handle;
	return handle;
}
