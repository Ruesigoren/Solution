/*
 * File: 4.3-SumofFirstNOdds.c
 * ---------------------------
 * This program calculate the sum of first N odd numbers;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i, n, odds, sum = 0;

	printf("This program calculate the sum of first N odd numbers.\n");
	printf("Please enter the number N: ");
	n = GetInteger();
	for (i = 0; i < n; i++) {
		odds = 2 * i + 1;
		sum += odds;
	}
	printf("The sum of first N odd numbers is %d\n", sum);
}