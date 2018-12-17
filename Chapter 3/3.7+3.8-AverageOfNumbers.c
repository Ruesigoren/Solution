/*
 * Filename£º3.7+3.8-AverageOfNumbers.c
 * ------------------------------------
 * This program gets numbers from users input and output the
 * average value of them on the screen.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i, value, sum;
	double average;
	int n;

	//printf("This program average a list of 5 integers.\n");
	printf("This program average a list of integers.\n");
	printf("How many values are there in the list? ");
	n = GetInteger();
	sum = 0;
	//for (i = 0; i < 5; i++)
	for (i = 0; i < n; i++) {
		printf("? ");
		value = GetInteger();
		sum += value;
	}
	//average = (double)sum / 5;
	average = (double)sum / n;
	printf("the average is %g\n", average);
}