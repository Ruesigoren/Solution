/*
 * File: 12.3-IsSorted.c
 * ---------------------
 * This program implements a predicate function IsSorted (array, n) that takes an integer array
 * and its effective size as parameters and returns TRUE if the array is sorted in nondecreasing order.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

 /* constants */

#define MaxArraySize          100

/* function prototypes */

static boolean IsSorted(int array[], int n);
static void PrintIntegerArray(int array[], int n);
static void SortIntegerArray(int array[], int n);
static int FindSmallestInteger(int array[], int low, int high);
static void SwapIntegerElements(int array[], int p1, int p2);

/* main program */

main()
{
	int test[] = { 1, 3, 2, 4, 6, 7, 18, 10, 12, 11, 5, 8, 9, 16, 13, 15, 14 };
	int len = sizeof(test) / sizeof(test[0]);
	int i, j, smallest;
	int temp;

	for (i = 0; i < len - 1; i++) {
		smallest = i;
		for (j = i + 1; j < len; j++) {
			if (test[smallest] > test[j]) {
				smallest = j;
			}
		}
		temp = test[i];
		test[i] = test[smallest];
		test[smallest] = temp;
	}
	if (IsSorted(test, len)) {
		PrintIntegerArray(test, len);
	}
}

boolean IsSorted(int array[], int n)
{
	int test_copy[MaxArraySize];
	int i;

	for (i = 0; i < n; i++) {
		test_copy[i] = array[i];
	}
	SortIntegerArray(test_copy, n);
	for (i = 0; i < n; i++) {
		if (test_copy[i] != array[i]) {
			return (FALSE);
		}
	}
	return (TRUE);
}

static void SortIntegerArray(int array[], int n)
{
	int lh, rh;

	for (lh = 0; lh < n - 1; lh++) {
		rh = FindSmallestInteger(array, lh, n - 1);
		SwapIntegerElements(array, lh, rh);
	}
}

static int FindSmallestInteger(int array[], int low, int high)
{
	int i, spos;

	spos = low;
	for (i = low + 1; i <= high; i++) {
		if (array[i] < array[spos]) {
			spos = i;
		}
	}
	return (spos);
}

static void SwapIntegerElements(int array[], int p1, int p2)
{
	int temp;

	temp = array[p1];
	array[p1] = array[p2];
	array[p2] = temp;
}

static void PrintIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
}
