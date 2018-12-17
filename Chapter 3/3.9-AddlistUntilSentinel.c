/*
 * File: 3.9-AddlistUntilSentinel.c
 * --------------------------------
 * This program adds a list of numbers.  The end of the
 * input is indicated by entering 0 as a sentinel value.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int value;
	int numbers = 0, sum = 0;
	double average;

	printf("This program average a list of integers.\n");
	printf("Enter -1 to signal the end of the list.\n");
	while (TRUE) {
		printf("? ");
		value = GetInteger();
		if (value == -1) break;
		sum += value;
		numbers++;
	}
	average = (double)sum / numbers;
	printf("The average  is %g.\n", average);
}
