/*
 * File: myalloc.c
 * ---------------
 * 
 */

#include <stdio.h>

#include "genlib.h"
#include "strlib.h"
#include "myalloc.h"

/* constants */

#define MaxMemorySize  1000

/* constants */

char Memory[MaxMemorySize + 1];
int cpos;

/* functions */

void InitialMemory(void)
{
	cpos = 0;
}

void *MyGetBlock(int nBytes)
{
	char *ch;

	Memory[MaxMemorySize] = '\0';
	//printf("%d\n", cpos);		test
	if (cpos + nBytes > MaxMemorySize) {
		Error("Not enough memory");
	}
	ch = Memory + cpos;
	cpos += nBytes;
	return ch;
}
