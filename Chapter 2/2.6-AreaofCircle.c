/*
 * File: 2.6-AreaofCircle.c
 * ------------------------
 * This program calculates the area of a circle.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double Pi = 3.14159;
	double area, radius;

	printf("This program calculate the area of a circle.\n");
	printf("The radius? ");
	radius = GetReal();
	area = Pi * radius * radius;
	printf("The area of this circle is %g\n", area);
}