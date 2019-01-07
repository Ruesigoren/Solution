/*
 * File: 12.11-Bubble Sort.c
 * -------------------------
 * This program reimplements the SortIntegerArray function
 * using the bubble sort algorithm.
 */

#include <stdio.h>

#include "random.h"
#include "simpio.h"

/* function prototypes */

void SortIntegerArray(int array[], int n);
void SwapIntegerElements(int array[], int p1, int p2);
void PrintIntegerArray(int array[], int n);

/* main program */

main()
{
	int test[100];
	int i;

	Randomize();
	for (i = 0; i < 100; i++) {
		test[i] = RandomInteger(1, 100);
	}
	SortIntegerArray(test, 100);
	PrintIntegerArray(test, 100);
}

void SortIntegerArray(int array[], int n)
{
	int i, j;

	for(i = 0; i < n - 1; i++){
		for (j = 0; j < n - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				SwapIntegerElements(array, j, j + 1);
			}
		}
	}
}

void SwapIntegerElements(int array[], int p1, int p2)
{
	int tmp;

	tmp = array[p1];
	array[p1] = array[p2];
	array[p2] = tmp;
}

void PrintIntegerArray(int array[], int n)
{
	int i, j;

	for (i = 0, j = 0; i < n; i++, j++) {
		if (j == 10) {
			printf("\n");
			j = 0;
		}
		printf("%4d", array[i]);
	}
	printf("\n\n");
}
