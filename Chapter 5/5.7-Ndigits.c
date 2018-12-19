/*
 * File: 5.7-Ndigits.c
 * -------------------
 * This program sums the digits in a positive integer.
 */

#include <stdio.h>

#define MaxNumber  1E+9

/* function prototypes */

int Ndigits(int n);

/* main program */

main()
{
	int i;

	for (i = 1; i <= MaxNumber; i *= 10) {
		printf("%d\n", Ndigits(i));
	}
}

int Ndigits(int n)
{
	int i = 0;

	while (n > 0) {
		n /= 10;
		i++;
	}
	return i;
}
