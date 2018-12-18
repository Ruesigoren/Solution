/*
 * File: 4.10+4.11-PrintStars.c
 * ----------------------------
 * This program prints 8 rows of stars.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* constants */

#define rows  8

/* main program */

main()
{
	/* 4.10 */
	/*
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/* 4.11 */
	int i, j, k, nstar, nblank;

	nblank = rows + 2;  //parallel shift to the right for 3 blanks
	for (i = 0; i < rows; i++) {
		nstar = 2 * i + 1;
		for (j = 0; j < nblank; j++) {
			printf(" ");
		}
		for (k = 0; k < nstar; k++) {
			printf("*");
		}
		printf("\n");
		nblank--;
	}
}
