/*
 * Fine: 6.7-Pi.c
 * --------------
 * This program computes approximations of the mathematical constant ¦Ð.
 */

#include <stdio.h>

/* main program */

main()
{
	int i;
	double sum = 0.0, term;

	for (i = 0; i < 10000; i++) {
		term = 1 / (2 * i + 1.0);
		if (i % 2) term *= -1;
		sum += term;
	}
	sum *= 4;
	printf("Pi = %g\n", sum);
}
