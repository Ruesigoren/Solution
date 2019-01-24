/*
 * File: 17.10-TestSortIntegerArray.c
 * ----------------------------------
 * This program choosing the cutoff point separating large arrays from small ones.
 */

#include <stdio.h>
#include <time.h>

#include "sort.h"
#include "random.h"

/* constants */

#define MaxArraySize 1000

/* function prototypes */

static void CopyIntegerArray(int source[], int destination[], int n);
static void GenerateIntegerArray(int array[], int n);
static void PrintIntegerArray(int array[], int n);

/* main program */

main()
{
	int array[MaxArraySize];
	int array2[MaxArraySize];
	double start, finish, elapsed;

	Randomize();
	GenerateIntegerArray(array, MaxArraySize);
	CopyIntegerArray(array, array2, MaxArraySize);
	start = clock();
	SelectSortIntegerArray(array, MaxArraySize);
	finish = clock();
	elapsed = (double)(finish - start) / CLOCKS_PER_SEC;
	//PrintIntegerArray(array, MaxArraySize);
	printf("Select Sort costed %f s\n", elapsed);
	start = clock();
	MergeSortIntegerArray(array, MaxArraySize);
	finish = clock();
	elapsed = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Merge Sort costed %f s\n", elapsed);
}

static void CopyIntegerArray(int source[], int destination[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		destination[i] = source[i];
	}
}

static void GenerateIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		array[i] = RandomInteger(1, n);
	}
}

static void PrintIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
}
