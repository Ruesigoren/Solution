/*
 * File: 3.1-AddNInteger.c
 * -----------------------
 * This program adds a list of N numbers, printing
 * the total at the end. N is given by users.
 * Instead of reading the numbers into separate variables, 
 * this program reads in each number and adds it to a running total.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i, n, value, total;

	printf("This program adds a list of N numbers.\n");
	total = 0;
	printf("Please input the number N = ");
	n = GetInteger();
	printf("Please input %d numbers\n", n);
	for (i = 0; i < n; i++)
	{
		printf(" ? ");
		value = GetInteger();
		total += value;
	}
	printf("The total is %d\n", total);
}