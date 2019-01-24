/*
 * File: 17.2-Combination.c
 * ------------------------
 * This is a recursive implementation of the Combinations function.
 */

#include <stdio.h>

#include "genlib.h"

/* constants */

#define  Nmax  10

/* function prototypes */

int C(int n, int k);

/* main program */

main()
{
	int i, j, k;

	for (i = 0; i < Nmax + 1; i++) {
		for (k = Nmax + 1 - i; k > 0; k--) {
			printf("  ");
		}
		for (j = 0; j <= i; j++) {
			//printf("%d%d ", i, j);
			printf("%3d ", C(i, j));
		}
		printf("\n");
	}
}

int C(int n, int k)
{
	if (n < 0 || k < 0) {
		Error("Illegal data");
	}
	else if (n == k) {
		return 1;
	}
	else if (k == 0) {
		return 1;
	}
	return C(n - 1, k) + C(n - 1, k - 1);
}
