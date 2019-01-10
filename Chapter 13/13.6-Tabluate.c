/*
 * File: 13.6-Tabluate.c
 * ---------------------
 * This function takes an array of integers and its effective size 
 * and writes out a tabulation showing the number of times each element appears.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "sort.h"

/* function prototypes */

void Tabluate(int *array, int n);

/* main program */

main()
{
	int array[] = { 91, 93, 98, 92, 92, 95, 93, 92, 91, 95, 99, 92, 98 };
	int n;

	n = sizeof(array) / sizeof(*array);
	Tabluate(array, n);
}

void Tabluate(int *array, int n)
{
	int *arr;
	int i, cpos;
	int nRepeat;
	int temp;

	arr = NewArray(n, int);
	for (i = 0; i < n; i++) {
		*(arr + i) = *(array + i);
	}
	SortIntegerArray(arr, n);
	for (i = 0; i < n; ) {
		nRepeat = 0;
		cpos = i;
		temp = arr[cpos];
		while (arr[i] == arr[cpos]) {
			i++;
			nRepeat++;
		}
		printf("%d: %d\n", temp, nRepeat);
	}
}
