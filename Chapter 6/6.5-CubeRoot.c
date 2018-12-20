/*
 * File: 6.5-CubeRoot.c
 * --------------------
 * This program express the Newton algorithm to find the cube root of a float-point number.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define Epsilon 0.0000000001

boolean ApproximatelyEqual(double x, double y);
double CubeRoot(double x);
void TestCubeRoot(double x);

main()
{
	double i;

	TestCubeRoot(0.0);
	TestCubeRoot(0.25);
	TestCubeRoot(1);
	TestCubeRoot(2);
	TestCubeRoot(3);
	TestCubeRoot(4);
	TestCubeRoot(81);
	TestCubeRoot(200);
	TestCubeRoot(1.0E12);
	printf("\nPlease Enter a number to be tested: ");
	i = GetReal();
	TestCubeRoot(i);
}

void TestCubeRoot(double x)
{
	double computed, actual;

	computed = CubeRoot(x);
	actual = pow(x, 1.0 / 3);
	printf("CubeRoot(%g) = %g  pow(%g, 1/3) = %g\n", x, computed, x, actual);
	if (!ApproximatelyEqual(computed, actual)) {
		printf("Warning! Computed value does not match actual!\n");
	}
}

double CubeRoot(double x)
{
	double g;

	if (x == 0) return (0);
	g = x;
	while (!ApproximatelyEqual(x, g * g * g)) {
		g = (g + x / (g * g)) / 2;
	}
	return g;
}

boolean ApproximatelyEqual(double x, double y)
{
	double num, den;

	num = fabs(x - y);
	den = min(fabs(x), fabs(y));
	if (num + den == num) return (x == y);
	return (num / den < Epsilon);
}
