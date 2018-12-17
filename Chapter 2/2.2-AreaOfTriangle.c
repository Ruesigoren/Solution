/*
 * File: 2.2-AreaOfTriangle.c
 * --------------------------
 * This program finds the area of a triangle.
 * multiply the base by the height, and then divide by 2.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double base, height, area;

	printf("This program finds the area of a triangle.\n");
	printf("Enter base : ");
	base = GetReal();
	printf("Enter height : ");
	height = GetReal();
	area = (base * height) / 2;
	printf("area = %g\n", area);
}