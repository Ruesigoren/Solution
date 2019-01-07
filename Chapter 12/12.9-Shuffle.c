/*
 * File: 12.9-Shuffle.c
 * --------------------
 * This program is a shuffling algorithm in which each 
 * possible output configuration is equally likely.
 * The program displays the integers between 1 
 * and 52 in a randomly sorted order.
 */

#include <stdio.h>

#include "random.h"
#include "simpio.h"

/* constants */

#define Nelements  52

/* function prototypes */

void ShuffleIntegerArray(int array[], int n);
int FindRandomInteger(int array[], int low, int high);
void SwapIntegerElements(int array[], int p1, int p2);
void PrintIntegerArray(int array[], int n);

/* main program */

main()
{
	int Integer[Nelements];
	int i;

	Randomize();
	for (i = 0; i < Nelements; i++) {
		Integer[i] = i + 1;
	}
	ShuffleIntegerArray(Integer, Nelements);
	PrintIntegerArray(Integer, Nelements);
}

void ShuffleIntegerArray(int array[], int n)
{
	int lh, rh;

	for (lh = 0; lh < n - 1; lh++) {
		rh = FindRandomInteger(array, lh, n - 1);
		SwapIntegerElements(array, lh, rh);
	}
}

int FindRandomInteger(int array[], int low, int high)
{
	return (RandomInteger(low, high));
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
		if (j == n / 4) {
			j = 0;
			printf("\n");
		}
		printf("%-4d", array[i]);
	}
	printf("\n");
}
