/*
 * File: 3.11-FormatePrintSquareAndCube.c
 * --------------------------------------
 * This program calculate the squraed value and cubed value of number 1-10;
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
	int squre, cube;

	printf("Number  Squre  Cube\n");
	for (int i = MIN; i <= MAX; i++) {
		squre = i * i;
		cube = i * i * i;
		printf("%6d  %5d  %4d\n", i, squre, cube);
	}
}