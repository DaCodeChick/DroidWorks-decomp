#include "d3d.h"

#include <cmath>
#include <ddraw.h>
#include <dsound.h>

// Win: 00647900
static LPDIRECTDRAW gDirectDraw = NULL;

// Win: 00647924
static LPDIRECTSOUND gDirectSound = NULL;

// Win: 00647938
static LPDIRECTSOUND3DBUFFER gDirectSound3DBuffer = NULL;

// Win: 00647940
static LPDIRECTSOUND3DLISTENER gDirectSound3DListener = NULL;

// Win: 0064793c
static LPDIRECTSOUNDBUFFER gDirectSoundBuffer = NULL;

// Win: 00647920
static LONG gDirectSoundVolume = 0;

// Win: 004ff750
void CleanupDirectDraw(void)
{
	if (gDirectDraw != NULL)
	{
		gDirectDraw->Release();
		gDirectDraw = NULL;
	}
	return;
}

// Win: 00500700
void CleanupDirectSound(void)
{
	if (gDirectSound3DBuffer != NULL)
	{
		gDirectSound3DBuffer->Release();
		gDirectSound3DBuffer = NULL;
	}
	if (gDirectSound3DListener != NULL)
	{
		gDirectSound3DListener->Release();
		gDirectSound3DListener = NULL;
	}
	if (gDirectSoundBuffer != NULL)
	{
		gDirectSoundBuffer->SetVolume(gDirectSoundVolume);
		gDirectSoundBuffer->Release();
		gDirectSoundBuffer = NULL;
	}
	if (gDirectSound != NULL)
	{
		gDirectSound->Release();
		gDirectSound = NULL;
	}
	return;
}

// Win: 00500770
void SetDirectSoundVolume(float value)
{
	LPDIRECTSOUNDBUFFER This;
	longlong lVar2;

	This = gDirectSoundBuffer;
	if (gDirectSoundBuffer != NULL)
	{
		lVar2 = (longlong)std::trunc((1.0f - value) * (1.0f - value) * -5000.0f);
		This->SetVolume((LONG)lVar2);
	}
	return;
}
