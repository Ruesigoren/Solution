/*
 * File: 8.5-CoinFlipping.c
 * ------------------------
 * This program simulates flipping a coin repeatedlly
 * and continus until 3 consecutive heads are tossed.
 */

#include <stdio.h>
#include <stdlib.h>

#include "genlib.h"
#include "random.h"

main()
{
	int i, j;

	Randomize();
	for (i = 0, j = 0; ; i++) {
		if (rand() <= RAND_MAX / 2) {
			printf("Heads\n");
			j++;
		}
		else {
			printf("Tails\n");
			j = 0;
		}
		if (j == 3) {
			printf("it took %d times to get heads 3 consecutive times\n", i + 1);
			break;
		}
	}
}