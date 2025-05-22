#include "util.h"

// Win: 005020d0
byte FindClosestColor(const byte *palette, uint count, float red, float green, float blue)
{
	const byte *pbVar1;
	float fVar2;
	uint uVar3;
	byte bVar4;
	const byte *pbVar6;
	float local_4;
	uint uVar5;

	uVar5 = 0;
	bVar4 = 0;
	uVar3 = 0;
	local_4 = 3.4e+38f;
	if (count != 0)
	{
		do
		{
			if (local_4 <= 0.0f)
			{
				return (byte)uVar5;
			}
			bVar4 = *palette;
			pbVar1 = palette + 1;
			pbVar6 = palette + 2;
			palette = palette + 3;
			fVar2 = ((float)*pbVar6 - blue) * ((float)*pbVar6 - blue) * 0.114f +
			        ((float)*pbVar1 - green) * ((float)*pbVar1 - green) * 0.587f +
			        ((float)bVar4 - red) * ((float)bVar4 - red) * 0.299f;
			if (fVar2 < local_4)
			{
				uVar5 = uVar3;
				local_4 = fVar2;
			}
			bVar4 = (byte)uVar5;
			uVar3 = uVar3 + 1;
		} while (uVar3 < count);
	}
	return bVar4;
}

// Win: 00501ba0
uint StringHash(const char *str, int divisor)
{
	const char *pcVar1;
	char cVar2;
	int iVar3;
	uint uVar4;

	iVar3 = 0;
	cVar2 = *str;
	while (cVar2 != '\0')
	{
		pcVar1 = str + 1;
		iVar3 = (int)cVar2 + iVar3 * 0x1003f;
		str = str + 1;
		cVar2 = *pcVar1;
	}
	uVar4 = iVar3 % divisor >> 0x1f;
	return (iVar3 % divisor ^ uVar4) - uVar4;
}
