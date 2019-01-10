/*
 * File: 13.3-RangeofValues.c
 * --------------------------
 * This program finds and returns simultaneously both the lowest 
 * and highest values in an array of type double.
 */

#include <stdio.h>
#include <math.h>

#include "simpio.h"
#include "genlib.h"

/* constants */

#define Epsilon    1e-10 
#define Nelements  100
#define Sentinel    -1

/* function prototypes*/

void GetRangeofArray(double *array, double *max, double *min, int len);
int GetRealArray(double *array, int max, double sentinel);

/* main program */

main()
{
	double Real[Nelements];
	int n;
	double max, min;

	printf("Enter the elements of the array, one perline.\n");
	printf("Use ¨C1 to signal the end of the list.\n");
	n = GetRealArray(Real, Nelements, Sentinel);
	GetRangeofArray(Real, &max, &min, n);
	printf("The range of value is between %g-%g\n", min, max);
}

void GetRangeofArray(double *array, double *max, double *min, int len)
{
	int i;
	int minindex, maxindex;

	minindex = maxindex = 0;;
	for (i = 1; i < len; i++) {
		if (*(array + i) > *(array + maxindex) &&
		*(array + i) - *(array + maxindex) > Epsilon) {
			maxindex = i;
		}
		if (*(array + i) < *(array + minindex) &&
		*(array + minindex) - *(array + i) > Epsilon) {
			minindex = i;
		}
	}
	*min = *(array + minindex);
	*max = *(array + maxindex);
}

int GetRealArray(double *array, int max, double sentinel)
{
	int n;
	double value;

	n = 0;
	while (TRUE) {
		printf(" ? ");
		value = GetReal();
		if (fabs(value - Sentinel) < Epsilon) break;
		if (n == max) Error("Too many input items for array");
		array[n] = value;
		n++;
	}
	return (n);
}
