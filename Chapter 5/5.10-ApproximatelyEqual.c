/*
 * File: 5.10-ApproximatelyEqual.c
 * -------------------------------
 * This Program determines wheather two float-point numbers are approximarely euqal or not.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"

/* constants */

#define Epsilon 1E-6

/* function prototypes*/

boolean ApproximatelyEqual(double x, double y);

/* main program */

main()
{
	double x;

	for (x = 1.0; ; x += 0.1) {
		printf("%.1f\n", x);
		if (ApproximatelyEqual(x, 2.0)) break;
	}
}

boolean ApproximatelyEqual(double x, double y)
{
	double num, den;

	num = fabs(x - y);
	den = min(fabs(x), fabs(y));
	if (num + den == num) return (x == y);
	return (num / den < Epsilon);
}
