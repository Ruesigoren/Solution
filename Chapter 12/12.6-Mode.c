/*
 * File: 12.6-Mode.c
 * -----------------
 * This program returns the mode of an array composed of integer values.
 * If there are several values that occur equally often and outnumber 
 * and of the other values (such distributions are called multimode), 
 * our function may return any of those values as the mode
 */

#include <stdio.h>

#include "simpio.h"
#include "random.h"
#include "genlib.h"
#include "sort.h"

/* constants */

#define Nelements          100

/* function prototypes */

int Mode(int array[], int n);
static void PrintIntegerArray(int array[], int n);
static void Print2dIntegerArray(int array[][2], int n);

/* main program */

main()
{
	int test[Nelements];
	int mode;
	int i;

	Randomize();

	/* generate test array */
	for (i = 0; i < Nelements; i++) {
		test[i] = RandomInteger(0, 100);
	}

	PrintIntegerArray(test, Nelements);
	mode = Mode(test, Nelements);
	printf("The mode of this array is %d\n", mode);
}

int Mode(int array[], int n)
{
	int i, j;
	int cpos;
	int nRepeat, nRemain;
	int Deduplication[Nelements][2];	//Deduplication[i][0] -- the elements
										//Deduplication[i][1] -- corresponding occurred times
	int max_occurred_times, nModes;
	int Modes[Nelements];

	SortIntegerArray(array, n);

	/* Deduplication */
	for (i = 0, j = 0; i < n; j++) {
		cpos = i;
		nRepeat = 0;
		while (array[i] == array[cpos]) {
			i++;
			nRepeat++;
		}
		Deduplication[j][0] = array[cpos];
		Deduplication[j][1] = nRepeat;
	}
	nRemain = j;

	/* show the result */

	printf("The deduplication array and frequence of each elements:\n\n");
	Print2dIntegerArray(Deduplication, nRemain);

	/* find the max occurred times */
	cpos = 0;
	for (i = 0; i < nRemain; i++) {
		if (Deduplication[i][1] > Deduplication[cpos][1]) {
			cpos = i;
		}
	}
	max_occurred_times = Deduplication[cpos][1];

	/* find out all the modes and save them to array */
	for (i = 0, j = 0; i < nRemain; i++) {
		if (Deduplication[i][1] == max_occurred_times) {
			Modes[j] = Deduplication[i][0];
			j++;
		}
	}
	nModes = j;

	/* show all the modes */
	printf("There are %d modes: ", nModes);
	for (i = 0; i < nModes; i++) {
		printf("%4d", Modes[i]);
	}
	printf("\n");

	/* randomly return one mode */
	return (Modes[RandomInteger(0, nModes - 1)]);
}

/*
 * Function: PrintIntegerArray
 * Usage: PrintIntegerArray(array, n);
 * -----------------------------------
 * This function displays the first n values in array,
 * one per line, on the console.
 */

static void PrintIntegerArray(int array[], int n)
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

static void Print2dIntegerArray(int array[][2], int n)
{
	int i, j;

	for (i = 0, j = 0; i < n; i++, j++) {
		if (j == 10) {
			printf("\n");
			j = 0;
		}
		printf("%4d", array[i][0]);
	}
	printf("\n\n");
	for (i = 0, j = 0; i < n; i++, j++) {
		if (j == 10) {
			printf("\n");
			j = 0;
		}
		printf("%4d", array[i][1]);
	}
	printf("\n\n");
}
