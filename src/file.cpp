#include "file.h"

// Win: 00442a50
void GetFileExtension(char **path)
{
	char cVar1;
	char *pcVar2;
	char *pcVar3;
	char *pcVar4;

	pcVar2 = *path;
	cVar1 = *pcVar2;
	pcVar4 = pcVar2;
	while (pcVar3 = pcVar2, cVar1 != '\0')
	{
		cVar1 = pcVar3[1];
		pcVar4 = pcVar3;
		while ((pcVar2 = pcVar4 + 1, cVar1 != '\0' && (cVar1 != '.')))
		{
			cVar1 = pcVar4[2];
			pcVar4 = pcVar2;
		}
		cVar1 = *pcVar2;
		pcVar4 = pcVar3;
	}
	*path = pcVar4;
	return;
}
