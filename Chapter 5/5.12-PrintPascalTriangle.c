/*
 * File: 5.12-PrintPascalTriangle.c
 * --------------------------------
 * This Program generates Pascal triangle.
 */

#include <stdio.h>

/* function prototypes */

int Combinations(int n, int k);
int Factorial(int n);

/* main program */

main()
{
	int i, j, rows = 8;

	for (i = 0; i < rows; i++) {
		for (j = 1; j < rows - i; j++) {  //print blanks
			printf("  ");
		}
		for (j = 0; j <= i; j++) {
			printf("%4d", Combinations(i, j));
		}
		printf("\n");
	}
}

int Combinations(int n, int k)
{
	return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
}

int Factorial(int n)
{
	int i, product = 1;

	for (i = 1; i <= n; i++) {
		product *= i;
	}
	return (product);
}
