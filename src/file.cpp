#include "file.h"
#include "typedefs.h"

// Win: 00502410
int MakeDirectory(const char *path)
{
	BOOL BVar1;
	BVar1 = CreateDirectoryA(path, NULL);
	return BVar1;
}

// Win: 00502420
int RemoveFile(const char *path)
{
	BOOL BVar1;

	BVar1 = DeleteFileA(path);
	return BVar1;
}

// Win: 004120f0
bool TryRemoveFile(const char *path)
{
	BOOL BVar1;

	BVar1 = RemoveFile(path);
	return BVar1 != 0;
}
