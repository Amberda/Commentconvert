#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#ifndef __COMMENT_H__
#define __COMMENT_H__

enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};
void DOCState(FILE *pfIn, FILE *pfOut);
void DOCppState(FILE *pfIn, FILE *pfOut);
void DONulState(FILE *pfIn, FILE *pfOut);
void DOConvetWork(FILE *pfIn, FILE *pfOut);


#endif //__COMMENT_H__

