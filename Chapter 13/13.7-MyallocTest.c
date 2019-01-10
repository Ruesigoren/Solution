/*
 * File: 13.7-MyallocTest.c
 * ------------------------
 * The myalloc.h exports a function MyGetBlock to simulate the dynamic allocation process.
 * Calling MyGetBlock (nBytes) will return a pointer to a block of memory that is nBytes long.
 * Each new memory block is taken from the large global array, beginning wherever the last block left off.
 */

#include <stdio.h>

#include "genlib.h"
#include "myalloc.h"


/* main program */

main()
{
	char *arr;
	int *arr2;
	int i;

	InitialMemory();
	//arr = MyGetBlock(1 * sizeof(char));
	arr2 = (int *)MyGetBlock(249 * sizeof(int));
	for (i = 0; i < 249; i++) {
		arr2[i] = i;
	}
	//arr[i] = '\0';
	for (i = 0; i < 249; i++) {
		printf("%d\n", arr2[i]);
	}
	arr = (char *)MyGetBlock(1 * sizeof(char));
	*arr = 'a';
	printf("%c\n", *arr);

	arr2 = (int *)MyGetBlock(1 * sizeof(int));	//print error prompt
	*arr2 = 3;
	printf("%d\n", *arr2);
}
