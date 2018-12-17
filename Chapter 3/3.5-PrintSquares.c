/*
 * File: 3.5-PrintSquares.c
 * ------------------------
 * This program calculate the squraed value of number 1-10;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constant: MAX, MIN
 * ------------------
 * To change the lower and upper limit,change the definition of the constants;
 * The constants must be int values.
 */

#define MAX 10
#define MIN 1

/* Main program */

main()
{
	int i;

	for (i = MIN; i <= MAX; i++) {
		printf("%d suqared is %d\n", i, i * i);
	}
}