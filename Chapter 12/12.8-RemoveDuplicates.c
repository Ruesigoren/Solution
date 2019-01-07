/*
 * File: 12.8-RemoveDuplicates.c
 * -----------------------------
 * This program removes all duplicate values from a sorted array of integers,
 * leaving only a single copy of each value.
 */

#include <stdio.h>

#include "simpio.h"

 /* function prototypes */

void PrintIntegerArray(int array[], int n);
int RemoveDuplicates(int array[], int n);

/* main program */

main()
{
	int scores[] = { 65, 72, 75, 79, 82, 82, 84, 84, 84, 86, 90, 94, 95 };	//sorted integer array
	int nScores = sizeof(scores) / sizeof(scores[0]);
	int nRemain;

	PrintIntegerArray(scores, nScores);
	printf("nScores: %d\n", nScores);
	nRemain = RemoveDuplicates(scores, nScores);
	PrintIntegerArray(scores, nRemain);
	printf("nScores: %d\n", nRemain);
}

int RemoveDuplicates(int array[], int n)
{
	int i, j;
	int tmp;

	j = 0;
	for (i = 0; i < n; i++) {
		tmp = array[i];
		while (i < n - 1 && array[i + 1] == tmp) {
			i++;
		}
		array[j] = tmp;
		j++;
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
