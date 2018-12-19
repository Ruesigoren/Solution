/*
 * File: 5.1-RootsOfQuadratic.c
 * ----------------------------
 * This program calculates the two solutions of the quadratic equation.
 */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

main()
{
	int a, b, c, x;

	printf("Enter cofficients for the quadratic equation.\n");
	printf("a: ");
	a = GetInteger();
	printf("b: ");
	b = GetInteger();
	printf("c: ");
	c = GetInteger();
	x = b * b - 4 * a * c;
	if (x >= 0) {
		printf("One root is %g\n", (-b + sqrt(x)) / (2 * a));
		printf("Another root is %g\n", (-b - sqrt(x)) / (2 * a));
	} else {
		printf("Error! This equation has no real roots\n");
	}
}