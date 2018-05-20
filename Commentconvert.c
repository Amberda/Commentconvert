#define _CRT_SECURE_NO_WARNINGS 1

#include "Commentconvert.h"

static enum STATE state = NUL_STATE;

void DONulState(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '/':
	{
				second = fgetc(pfIn);
				if (second == '*')
				{
					fputc('/', pfOut);
					fputc('/', pfOut);
					state = C_STATE;
				}
				else if (second == '/')
				{
					fputc(first, pfOut);
					fputc(second, pfOut);
					state = CPP_STATE;
				}
				else
				{
					fputc(first, pfOut);
					fputc(second, pfOut);
				}
	}
		break;
	case EOF:
	{
				state = END_STATE;
	}
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DOConvetWork(FILE *pfIn, FILE *pfOut)
{
	while (state != END_STATE)
	{
		switch (state)
		{
		case C_STATE:
			DOCState(pfIn, pfOut);
			break;
		case CPP_STATE:
			DOCppState(pfIn, pfOut);
			break;
		case NUL_STATE:
			DONulState(pfIn, pfOut);
			break;
		}
	}
}
void DOCState(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
	{
				 fputc('\n', pfOut);
				 fputc('/', pfOut);
				 fputc('/', pfOut);
	}
		break;
	case '*':
	{
				second = fgetc(pfIn);
				if (second == '/')
				{
					state = NUL_STATE;
					third = fgetc(pfIn);
					switch (third)
					{
					case '\n':
						fputc('\n', pfOut);
						break;
					case '/':
						ungetc('/', pfIn);
					    fputc('\n', pfOut);
						break;
					default:
						fputc('\n', pfOut);
						fputc(third, pfOut);
						break;
					}
				}
				else if (second == '*')
				{
					fputc(second, pfOut);
					ungetc('*', pfIn);
				}
				else
				{
					fputc(first, pfOut);
					fputc(second, pfOut);
				}
				break;
	}
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DOCppState(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	/*int second = 0;*/
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		fputc(first, pfOut);
		state = NUL_STATE;
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}