/*
 * Fine: 6.9-Pi.c
 * --------------
 * This program computes approximations of the mathematical constant ¦Ð.
 */

#include <stdio.h>
#include <math.h>

#define N 100;

main()
{
	int radius = 2;
	double width, x, y, area;

	y = 0.0;
	width = 2.0 / N;
	for (x = 0; x < radius; x += width) {
		y += sqrt(4 - x * x);
	}
	area = y * width;
	printf("Pi = %g\n", area);
}
