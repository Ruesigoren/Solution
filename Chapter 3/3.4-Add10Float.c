/*
 * File: 3.4-Add10Float.c
 * ----------------------
 * This program adds a list of ten float-point numbers, printing
 * the total at the end.  Instead of reading the numbers
 * into separate variables, this program reads in each
 * number and adds it to a running total.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i;
	double value, total;

	printf("This program adds a list of ten float-point numbers.\n");
	total = 0;
	for (i = 0; i < 10; i++) {
		printf(" ? ");
		value = GetReal();
		total += value;
	}
	printf("The total is %f\n", total);
}
