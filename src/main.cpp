#include "ghidra.h"

static char gStringBuffer[64] = {0};
static char gBasePath[] = "\\";
static char gMoviePath[] = "Movie";

static bool CheckInstall(void)
{
	char cVar1;
	BYTE BVar2;
	bool bVar3;
	bool bVar4;
	HRSRC hInstance;
	LSTATUS LVar5;
	int iVar6;
	BOOL BVar7;
	HANDLE hFindFile;
	uint uVar8;
	uint uVar9;
	BYTE *pBVar10;
	char *pcVar11;
	char *pcVar12;
	BYTE *pBVar13;
	bool local_b56;
	HKEY pHStack_b54;
	DWORD DStack_b50;
	DWORD DStack_b4c;
	BYTE aBStack_b48[MAX_PATH];
	CHAR aCStack_a44[MAX_PATH];
	CHAR aCStack_940[2048];
	_WIN32_FIND_DATAA _Stack_140;

	bVar4 = true;
	bVar3 = false;
	hInstance = FindResourceA(NULL, "DroidWorks.rc", (LPCSTR)RT_STRING);
	LoadStringA((HINSTANCE)hInstance, 0x6c, gStringBuffer, 0x40);
	LVar5 = RegOpenKeyExA((HKEY)HKEY_LOCAL_MACHINE,
	                      "SOFTWARE\\Lucas_Learning_Ltd\\Star Wars DroidWorks\\1.0",
	                      REG_OPTION_NON_VOLATILE, KEY_READ, &pHStack_b54);
	if (LVar5 == 0)
	{
		DStack_b4c = MAX_PATH;
		LVar5 = RegQueryValueExA(pHStack_b54, "SourcePath", NULL, &DStack_b50, aBStack_b48,
		                         &DStack_b4c);
		RegCloseKey(pHStack_b54);
		if ((LVar5 != 0) || (DStack_b50 != 1))
		{
			LoadStringA((HINSTANCE)hInstance, 0x6b, aCStack_940, 0x7ff);
			iVar6 = MessageBoxA(NULL, aCStack_940, gStringBuffer, 0x30);
			goto code_r0x0041b37f;
		}
	}
	else
	{
		RegCloseKey(pHStack_b54);
		LoadStringA((HINSTANCE)hInstance, 0x67, aCStack_940, 0x7ff);
		iVar6 = MessageBoxA(NULL, aCStack_940, gStringBuffer, MB_ICONWARNING);
	code_r0x0041b37f:
		bVar3 = iVar6 != 1;
		bVar4 = false;
	}
	if (!bVar4)
	{
		if (bVar3)
		{
			GetCurrentDirectoryA(MAX_PATH, (LPSTR)aBStack_b48);
			uVar8 = 0xffffffff;
			pcVar11 = gBasePath;
			do
			{
				pcVar12 = pcVar11;
				if (uVar8 == 0)
					break;
				uVar8 = uVar8 - 1;
				pcVar12 = pcVar11 + 1;
				cVar1 = *pcVar11;
				pcVar11 = pcVar12;
			} while (cVar1 != '\0');
			uVar8 = ~uVar8;
			bVar4 = true;
			iVar6 = -1;
			pBVar10 = aBStack_b48;
			do
			{
				pBVar13 = pBVar10;
				if (iVar6 == 0)
					break;
				iVar6 = iVar6 + -1;
				pBVar13 = pBVar10 + 1;
				BVar2 = *pBVar10;
				pBVar10 = pBVar13;
			} while (BVar2 != '\0');
			pBVar10 = (BYTE *)(pcVar12 + -uVar8);
			pBVar13 = pBVar13 + -1;
			for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1)
			{
				*(undefined4 *)pBVar13 = *(undefined4 *)pBVar10;
				pBVar10 = pBVar10 + 4;
				pBVar13 = pBVar13 + 4;
			}
			for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1)
			{
				*pBVar13 = *pBVar10;
				pBVar10 = pBVar10 + 1;
				pBVar13 = pBVar13 + 1;
			}
		}
		if (!bVar4)
		{
			return false;
		}
	}
	local_b56 = false;
	GetCurrentDirectoryA(MAX_PATH, aCStack_a44);
	uVar8 = 0xffffffff;
	pcVar11 = gMoviePath;
	do
	{
		pcVar12 = pcVar11;
		if (uVar8 == 0)
			break;
		uVar8 = uVar8 - 1;
		pcVar12 = pcVar11 + 1;
		cVar1 = *pcVar11;
		pcVar11 = pcVar12;
	} while (cVar1 != '\0');
	uVar8 = ~uVar8;
	iVar6 = -1;
	pBVar10 = aBStack_b48;
	do
	{
		pBVar13 = pBVar10;
		if (iVar6 == 0)
			break;
		iVar6 = iVar6 + -1;
		pBVar13 = pBVar10 + 1;
		BVar2 = *pBVar10;
		pBVar10 = pBVar13;
	} while (BVar2 != '\0');
	pBVar10 = (BYTE *)(pcVar12 + -uVar8);
	pBVar13 = pBVar13 + -1;
	for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1)
	{
		*(undefined4 *)pBVar13 = *(undefined4 *)pBVar10;
		pBVar10 = pBVar10 + 4;
		pBVar13 = pBVar13 + 4;
	}
	for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1)
	{
		*pBVar13 = *pBVar10;
		pBVar10 = pBVar10 + 1;
		pBVar13 = pBVar13 + 1;
	}
	do
	{
		BVar7 = SetCurrentDirectoryA((LPCSTR)aBStack_b48);
		if (BVar7 != 0)
			goto LAB_0041b47d;
		LoadStringA((HINSTANCE)hInstance, 0x69, aCStack_940, 0x7ff);
		iVar6 = MessageBoxA(NULL, aCStack_940, gStringBuffer, MB_RETRYCANCEL | MB_ICONERROR);
	} while (iVar6 == 4);
LAB_0041b4da:
	if (local_b56 == false)
	{
		LoadStringA((HINSTANCE)hInstance, 0x6a, aCStack_940, 0x7ff);
		MessageBoxA(NULL, aCStack_940, gStringBuffer, MB_ICONWARNING);
	}
	SetCurrentDirectoryA(aCStack_a44);
	return local_b56;
	while (true)
	{
		LoadStringA((HINSTANCE)hInstance, 0x69, aCStack_940, 0x7ff);
		iVar6 = MessageBoxA(NULL, aCStack_940, gStringBuffer, MB_RETRYCANCEL | MB_ICONERROR);
		if (iVar6 != 4)
			break;
	LAB_0041b47d:
		hFindFile = FindFirstFileA("Droids.san", &_Stack_140);
		if (hFindFile != (HANDLE)0xffffffff)
		{
			local_b56 = true;
			FindClose(hFindFile);
			break;
		}
	}
	goto LAB_0041b4da;
}
