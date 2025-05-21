#include "util.h"

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
