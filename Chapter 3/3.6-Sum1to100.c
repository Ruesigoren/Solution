/*
 * File: 3.6-Sum1to100.c
 * ---------------------
 * This program calculate the sum of numbers 1 to 100.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* constants */

#define MAX 100
#define MIN 1

/* main program */

main()
{
	int sum ,numbers;

	numbers = MAX - MIN + 1;
	sum = ((MAX + MIN) / 2.0) * numbers;
	printf("This program calculate the sum of numbers %d to %d.\n", MIN, MAX);
	printf("The sum of numbers from %d to %d is %d\n", MIN, MAX, sum);
}