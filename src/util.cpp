#include "util.h"

void memswap(void *dst, void *src, size_t len)
{
	undefined1 uVar1;

	if ((dst != src) && (len != 0))
	{
		do
		{
			uVar1 = *(byte *)dst;
			*(undefined1 *)dst = *(byte *)src;
			dst = (void *)((ulonglong)dst + 1);
			*(undefined1 *)src = uVar1;
			src = (void *)((ulonglong)src + 1);
			len = len - 1;
		} while (len != 0);
	}
	return;
}
