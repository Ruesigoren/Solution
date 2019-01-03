/*
 * File: 11.3+11.4-StandardDeviation.c
 * -----------------------------------
 * 11.3 returns the mean of an array of type double whose effective size is n.
 *
 * 11.4 takes an array of floating-point values and the effective size of that array and returns the
 * standard deviation of the data distribution contained in the array.
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * Nelemtes -- Number of elements
 */

#define Nelements 7

/* function prototypes */

double StandardDeviation(double array[], int n);
double Mean(double array[], int n);

/* Main program */

main()
{
    double Data[Nelements];
    int i;

    printf("Please enter the data.\n");
    for (i = 0; i < Nelements; i++) {
        printf("data #%d:  ", i + 1);
        Data[i] = GetReal();
    }
	printf("The standard deviation is %.2f\n", StandardDeviation(Data, Nelements));
}

double StandardDeviation(double array[], int n)
{
	double average;
	double deviation[Nelements];
	double standardeviation;
	int i;

	average = Mean(array, n);
	for (i = 0; i < n; i++) {
		deviation[i] = array[i] - average;
		deviation[i] *= deviation[i];
	}
	average = Mean(deviation, n);
	standardeviation = sqrt(average);
	return (standardeviation);
}

double Mean(double array[], int n)
{
	double total, average;
	int i;

	total = 0;
	for (i = 0; i < n; i++) {
		total += array[i];
	}
	average = total / Nelements;
	return (average);
}
