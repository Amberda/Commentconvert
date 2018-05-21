#define _CRT_SECURE_NO_WARNINGS 1

#include "Commentconvert.h"

int main()
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;
	pfRead = fopen("input.c","r" );
	if (pfRead == NULL)
	{
		perror("Open file for read.");
		return;
	}
	pfWrite = fopen("output.c", "w");
	if (pfWrite == NULL)
	{
		perror("Open file for write.");
		fclose(pfRead);
		return;
	}
	DOConvetWork(pfRead, pfWrite);
	fclose(pfRead);
	fclose(pfWrite);
	system("pause\n");
	return 0;
}
