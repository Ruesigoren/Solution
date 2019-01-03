/*
 * File: 11.5-FindPrime.c
 * ----------------------
 * This program uses the sieve of Eratosthenes to generate a list of the primes between 2 and 1000.
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * maxnumber -- the range of numbers.
 */

#define maxnumber          2000

/*
 * Private variables
 * -----------------
 * cpos -- Current position in the array.
 */

static int cpos = 2;

/* function prototype */

void SieveofEratosthenes(int array[], int n);
void InitialIntegerArray(int array[], int n);

/* main program */

main()
{
	int Number[maxnumber];

	InitialIntegerArray(Number, maxnumber);
	SieveofEratosthenes(Number, maxnumber);
}


void SieveofEratosthenes(int array[], int n)
{
	int i, j;

	for (i = 2; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (array[j] != 0 && j % i == 0) {
				array[j] = 0;
			}
		}
	}
	for (i = 2; i < n; i++) {
		if (array[i] != 0) {
			printf("%-6d", i);
		}
	}
}

void InitialIntegerArray(int array[], int n)
{
	for (int i = 0; i < n; i++) {
		array[i] = 1;
	}
}
