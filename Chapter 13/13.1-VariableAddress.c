/*
 * File: 13.1-VariableAddress.c
 * ----------------------------
 * This program displays the addresses for the global variables and local variables.
 */

#include <stdio.h>

/* global variables */

static int globalCount;
static double globalArray[100];
static char *globalPointer;

/* main program */

main()
{
	int count;
	double array[100];
	char *cp;
	void *vp;

	vp = &globalCount;
	printf("Address of globalCount is %lu\n",(long)vp);
	vp = &globalArray;
	printf("Address of globalArray is %lu\n", (long)vp);
	vp = &globalPointer;
	printf("Address of globalPointer is  %lu\n", (long)vp);
	vp = &count;
	printf("Address of count is  %lu\n", (long)vp);
	vp = &array;
	printf("Address of array is %lu\n", (long)vp);
	vp = &cp;
	printf("Address of cp is %lu\n", (long)vp);
	vp = &vp;
	printf("Address of vp = %lu\n", (long)vp);
}
