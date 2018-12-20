/*
 * Fine: 6.7-Pi.c
 * --------------
 * This program computes approximations of the mathematical constant ¦Ð.
 */

#include <stdio.h>

int Pow(int x, int y);

main()
{
	int i;
	double term = 0.0;

	for (i = 0; i < 10000; i++)
	{
		term += Pow(-1, i) / (2 * i + 1.0);
	}
	term *= 4;
	printf("Pi = %g\n", term);
}

int Pow(int x, int y)
{
	int i, result = 1;

	if (y == 1) {
		result = x;
	}
	if (y > 1) {
		for (i = 0; i < y; i++) {
			result *= x;
		}
	}
	return result;
}
