/*
 * File: 8.3-RandomPhoneNumber.c
 * -----------------------------
 * This program generates a random phone number.
 * The output contains a hyphen between the third and fourth digit.
 * Neither of the first two digits is 0 or 1.
 */

#include <stdio.h>
#include <stdlib.h>

#include "random.h"

/*
 * Constants
 * ---------
 * NTrials -- Number of trials
 */

#define NTrials 100

/* function prototypes */

void RandomPhoneNumber(void);

/* Main program */

main()
{
	int i;

	Randomize();
	for (i = 0; i < NTrials; i++) {
		RandomPhoneNumber();
	}
}

void RandomPhoneNumber(void)
{
	int i;

	for (i = 0; i < 2; i++) {
		printf("%d", RandomInteger(2, 9));
	}
	for (i = 0; i < 5; i++) {
		printf("%d", RandomInteger(0, 9));
		if (i == 0) {
			printf("-");
		}
	}
	printf("\n");
}