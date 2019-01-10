/*
 * File: 13.5-IndexArray.c
 * -----------------------
 * This program returns a pointer to a dynamically allocated 
 * integer array with n elements, each of which is initialized
 * to its own index.
 */

#include <stdio.h>
#include <stdlib.h>

#include "simpio.h"
#include "genlib.h"

/* function  prototypes */

int *IndexArray(int n);

/* main program */

main()
{
	int *ip;
	int i;

	ip = IndexArray(10);
	printf("ip = %lu\n", (long)ip);  //print ip
	for (i = 0; i < 10; i++) {
		/* 2 methods below are choosable*/
		//printf("%d\n", *(ip++));  //ip increase
		printf("%d\n", *(ip + i));  //ip remain unchanged
	}
	printf("ip = %lu\n", (long)ip);  //print ip
}

int *IndexArray(int n)
{
	int *arr;
	int i;

	/*
	arr = (int *)malloc(10 * sizeof(int));
	if (arr == NULL) Error("No memory avaiable");
	*/

	arr = (int *)GetBlock(10 * sizeof(int));
	for (i = 0; i < n; i++) {
		*(arr + i) = i;
	}
	return (arr);
}
