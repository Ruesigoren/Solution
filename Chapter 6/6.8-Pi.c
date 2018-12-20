/*
 * Fine: 6.8-Pi.c
 * --------------
 * This program computes approximations of the mathematical constant ¦Ð.
 */

#include <stdio.h>

main()
{
	double sum, term, part1, part2, part3;
	int i;

	sum = 0;
	term = 0.5;
	part1 = 1;
	part3 = 0.5;

	for (i = 1; sum != sum + term; i++) {
		sum += term;
		part1 *= (2 * i - 1.0) / (2 * i);
		part2 = 1.0 / (2 * i + 1);
		part3 *= 0.25;
		term = part1 * part2 * part3;
	}
	sum *= 6.0;
	printf("Pi = %.10f\n", sum);
}
