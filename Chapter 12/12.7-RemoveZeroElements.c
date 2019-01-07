/*
 * File: 12.7-RemoveZeroElements.c
 * -------------------------------
 * This program goes through an array of integers and eliminates any elements whose value is 0.
 */

#include <stdio.h>

#include "simpio.h"

/* function prototypes */

void PrintIntegerArray(int array[], int n);
int RemoveZeroElements(int array[], int n);

/* main program */

main()
{
	int scores[] = { 65, 0, 95, 0, 0, 79, 82, 0, 84, 94, 86, 90, 0 };
	int nScores = sizeof(scores) / sizeof(scores[0]);
	int nRemain;
	/*
	printf("%d\n", nScores);
	*/
	PrintIntegerArray(scores, nScores);
	printf("nScores: %d\n", nScores);
	nRemain = RemoveZeroElements(scores, nScores);
	PrintIntegerArray(scores, nRemain);
	printf("nScores: %d\n", nRemain);
}

int RemoveZeroElements(int array[], int n)
{
	int i, j;

	for (i = 0, j = 0; i < n; i++) {
		while (array[i] == 0) {
			i++;
		}
		if (i < n) {
			array[j] = array[i];
			j++;
		}
	}
	return j;
}

void PrintIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%-4d", array[i]);
	}
	printf("\n");
}
