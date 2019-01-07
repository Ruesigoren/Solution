/*
 * File: 12.10-Dutch Flag.c
 * ------------------------
 * Dutch Nationl Flag progarm:
 * Suppose that you have an array with n elements each of which is a 
 * character¡ª'R', 'W' or 'B'¡ªrepresenting one of the colors in the Dutch flag. 
 * you need to rearrange these characters so that they appear in the same order
 * as they do in the Dutch flag: all the reds, followed by all the whites, followed by all the blues.
 * 
 * This program implements the Dutch  Flag algorithm 
 */

#include <stdio.h>

#include "simpio.h"

/* function prototypes */

void PrintCharArray(char array[], int n);
void SortDutchFlag(char array[], int n);
void SwapCharElements(char array[], int p1, int p2);

/* main program */

main()
{
	char DutchFlag[] = { 'R', 'B', 'W', 'W', 'B', 'B', 'R', 'W', 'W', 'R', 'R', 'W', 'R', 'B', 'W' };
	int len = sizeof(DutchFlag) / sizeof(DutchFlag[0]);

	printf("Initial states:\n");
	PrintCharArray(DutchFlag, len);
	SortDutchFlag(DutchFlag, len);
}

void SortDutchFlag(char array[], int n)
{
	int i, j, k;

	j = k = 0;
	for (i = 0; i < n; i++) {	//i -- Index of array element
								//j -- Number of 'R' flag
								//k -- Number of 'B' flag
		if (array[i] == 'R') {
			j++;
			if (i > j - 1) {  //do not need to sort first j 'R' flags
				SwapCharElements(array, i, j - 1);
				printf("Swapping position %d and %d\n", j - 1, i);
				PrintCharArray(array, n);
				i--;  //after exchanging position, we need to get back to position i - 1, so next loop will start at i
			}
		}
		if (array[i] == 'B') {
			k++;
			if (i < n - k) {  //do not need to sort last k 'B' flags
				SwapCharElements(array, i, n - k);
				printf("Swapping position %d and %d\n", i, n - k);
				PrintCharArray(array, n);
				i--;
			}
		}
	}
}

void SwapCharElements(char array[], int p1, int p2)
{
	char temp;

	temp = array[p1];
	array[p1] = array[p2];
	array[p2] = temp;
}

void PrintCharArray(char array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%-2c", array[i]);
	}
	printf("\n");
}
