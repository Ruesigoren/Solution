/*
 * File: 6.2-PrimesFactorization.c
 * -------------------------------
 * This program factorizes an integer into primes.
 */

#include <stdio.h>
#include "simpio.h"

main()
{
	int integer, i;

	i = 2;
	printf("Enter number to be factored.\n");
	printf("The number must greater than 1.\n");
	printf("? ");
	integer = GetInteger();
	while (integer > 1) {
		if (integer % i == 0) {
			integer /= i;
			if (integer == 1) {
				printf("%d\n", i);
			}
			else
				printf("%d * ", i);
		}
		else
			i++;
	}
}
