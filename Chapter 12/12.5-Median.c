/*
 * File: 12.5-Median.c
 * -------------------
 * This programs returns the median of an 
 * array of floating - point values.
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"
#include "sort.h"

/*
 * Constants
 * ---------
 * MaxScores -- Maximum number of scores
 * Sentinel  -- Value used to terminate input
 */

#define Nelements 100
#define Sentinel   -1
#define Epsilon   0.000001

/* Private function prototypes */

double Median(double array[], int n);
static int GetRealArray(double array[], int max, double sentinel);
static void PrintRealArray(double array[], int n);

main()
{
	double Real[Nelements];
	int n;
	double median;

	printf("Enter floating point number, one per line,\n");
	printf("ending with the sentinel value %d.\n", Sentinel);
	n = GetRealArray(Real, Nelements, Sentinel);
	median = Median(Real, n);
	printf("\nThe sorted numbers are:\n");
	PrintRealArray(Real, n);
	printf("\nThe Median is: %g\n", median);
}

double Median(double array[], int n)
{
	double median;

	SortRealArray(array, n);
	if (n % 2 == 0) {
		median = (array[n / 2 - 1] + array[n / 2]) / 2;
	}
	else {
		median = array[n / 2];
	}
	return median;
}

static int GetRealArray(double array[], int max, double sentinel)
{
	int n;
	double value;

	n = 0;
	while (TRUE) {
		printf(" ? ");
		value = GetReal();
		if (fabs(value - sentinel) < Epsilon) break;
		if (n == max) Error("Too many input items for array");
		array[n] = value;
		n++;
	}
	return (n);
}

static void PrintRealArray(double array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%g\n", array[i]);
	}
}
