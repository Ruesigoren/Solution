/*
 * File: 2.10-AverageOf4Intergers.c
 * --------------------------------
 * This program calculate average of 4 intergers;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int sum;
	double average;

	printf("This program calculate average of 4 Integers.\n");
	printf("Please input the 1st Integer: ");
	sum = GetInteger();
	printf("Please input the 2nd Integer: ");
	sum += GetInteger();
	printf("Please input the 3rd Integer: ");
	sum += GetInteger();
	printf("Please input the 4th Integer: ");
	sum += GetInteger();
	average = sum / 4.0;
	printf("The average of 4 integers is %g\n", average);
}