/*
 * File: 8.2-RandomEven.c
 * ----------------------
 * This program generates a random even number.
 */

#include <stdio.h>

#include "random.h"

/*
 * Constants
 * ---------
 * NTrials -- Number of trials
 */

#define NTrials 10

/* function prototypes */

int RandomEven(int low, int high);

/* Main program */

main()
{
	int i, r;

	Randomize();
	printf("Here are the results of %d calls to RandomEven:\n", NTrials);
	for (i = 0; i < NTrials; i++) {
		r = RandomEven(2, 100);
		printf("%10d\n", r);
	}
}

int RandomEven(int low, int high)
{
	int k, j;
	double d;

	d = (double)rand() / ((double)RAND_MAX + 1);
	k = (int)(d * (high - low + 1));
	j = low + k;
	return j % 2 + j;
}
